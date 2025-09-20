/*
 * adc.c
 *
 * Created: 8/21/2025 8:58:44 AM
 *  Author: Robert
 */

#include "HPB_lv_power_sys.h"
#include "adc.h"

int ADC_init()
{
	uint8_t ch = 0;
	uint8_t t_base = 0;
	adc_active_ch = 0xFF;		// 0xFF signals "ready to convert"

	// set up arrays
	for (ch = 0; ch < ADC_NUM_CH; ch++)
	{
		adc_results[ch] = 0xFFFE;			// initial results values
		adc_gain_uv[ch] = eeprom_read_word(ch + ADC_GAIN_EEP_ADDR);
		adc_offset_mv[ch] = eeprom_read_word(ch + ADC_OFF_EEP_ADDR);
	}

	// configure voltage reference : 2.5V reference, always on
	VREF.CTRLA = VREF_AC0REFSEL_2V5_gc;
	VREF.CTRLB = VREF_ADC0REFEN_bm;

	// set ADC clock prescalar; divide by 4 for compatibility with most clocks
	ADC0.CTRLB = ADC_PRESC_DIV4_gc;

	// set up ADC control register C : select reference voltage and provide 1usec timebase

	if ((F_CPU % 1000000) != 0) t_base = (F_CPU / 1000000) +1;
	else t_base = (F_CPU / 1000000);

	t_base = t_base << 3;

	ADC0.CTRLC = ADC_REFSEL_2500MV_gc | t_base;

	// add a few extra clock cycles for sampling; existing design uses amplifier buffers, but other revisions might not
	ADC0.CTRLE = 3;

	return 0;
}


int ADC_isDone()
{
	if (adc_active_ch == 0xff) return 1;
	else return 0;

}


int ADC_startSweep()
{
	// return early if system has not completed a run
	if (adc_active_ch != 0xff) return -1;

	// set index and mux channel
	adc_active_ch = 0;
	ADC0.MUXPOS = adc_channels[adc_active_ch];

	// enable interrupt
	ADC0.INTCTRL = ADC_SAMPRDY_bm;

	// initiate conversion
	ADC0.COMMAND = ADC_START_IMMEDIATE_gc;

	return 0;

}


uint16_t ADC_getResult(uint8_t res)
{

	if (res >= ADC_NUM_CH) return 0xFFFF;

	return adc_results[res];

}



int16_t ADC_getResultMv(uint8_t res)
{
	int32_t temp = 0;

	// flag bad result
	if (res >= ADC_NUM_CH) return 0;

	// pull raw value
	temp = ADC_getResult(res);

	// apply gain
	temp *= adc_gain_uv[res];

	// scale to mV
	temp /= 1000;

	// apply offset
	temp += adc_offset_mv[res];

	return (int16_t) temp;


}

ISR(ADC0_SAMPRDY_vect)
{
	// store measurement
	adc_results[adc_active_ch] = ADC0.SAMPLE;

	// next channel
	adc_active_ch++;

	// start conversion if not done with sweep
	if (adc_active_ch < ADC_NUM_CH)
	{
		ADC0.MUXPOS = adc_channels[adc_active_ch];
		ADC0.COMMAND = ADC_START_IMMEDIATE_gc;
	}
	// otherwise disable interrupt and flag "ready to re-run"
	else
	{
		ADC0.INTCTRL = 0;
		adc_active_ch = 0xFF;
	}


}