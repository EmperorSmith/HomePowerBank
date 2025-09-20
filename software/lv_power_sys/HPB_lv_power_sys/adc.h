/*
 * adc.h
 *
 * Created: 8/21/2025 8:58:55 AM
 *  Author: Robert
 */


#ifndef ADC_H_
#define ADC_H_

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/eeprom.h>

#define ADC_NUM_CH 5
#define UV_PER_LSB 610		// results in being low by about 1.5mV at full scale value for a 2.5V reference

uint16_t adc_results[ADC_NUM_CH];

#define ADC_GAIN_EEP_ADDR 64
#define ADC_OFF_EEP_ADDR 80

const ADC_MUXPOS_t adc_channels[ADC_NUM_CH] = {ADC_MUXPOS_AIN8_gc, ADC_MUXPOS_AIN6_gc, ADC_MUXPOS_AIN7_gc, ADC_MUXPOS_AIN9_gc, ADC_MUXPOS_VDDDIV10_gc};

uint8_t adc_active_ch;						// current channel under conversion

uint16_t adc_gain_uv[ADC_NUM_CH];			// adc channel gain values, in uV per LSb
int16_t adc_offset_mv[ADC_NUM_CH];			// adc channel offsets, in mV

/// Set up ADC system
///
/// This function configures the ADC for general operations. The PGA, if present,
/// is not utilized. Some extra clock cycles are added to improve settling time.
/// The base ADC clock is set to 1/4 of the main oscillator; this should provide
/// compatibility with a wide range of common clock rates. It uses the internal
/// 2.5V reference, which allows the system to operate with main supply rails down
/// to a little under 3V.
///
/// @return 0 if success, else if failure
int ADC_init();


/// Start all-channel measurement sequence
///
/// This function initiates a series of measurements, one for each configured
/// channel in a pre-determined list. The conversions trigger interrupts on
/// completion; the ISR will handle data storing and initiating the next
/// conversion in the sequence. This function will not interrupt an already-
/// running sequence.
///
/// @return 0 if success, -1 if busy, else if failure
int ADC_startSweep();


/// Check to see if ADC is done measuring channels
///
/// This function is a simple check on whether the ADC is done converting
/// the set of input channels.
///
/// @return 0 if not done, else done
int ADC_isDone();


/// Get ADC conversion result for a channel
///
/// This function returns the last measured value of a given channel. Two error
/// values are possible: 0xFFFF for bad channel parameter, and 0xFFFE for channel
/// has not yet been converted. The value returned is the raw ADC value, not scaled
///
/// @param res channel for which to return measurement
///
/// @return 0xFFFF for bad parameter, 0xFFFE for never measured, else raw ADC reading
uint16_t ADC_getResult(uint8_t res);

/// Get adjusted ADC conversion result for a channel
///
/// This function returns the last measured value of a given channel, scaled to the
/// appropriate number of millivolts. This function uses channel calibration factors
/// that are stored in EEPROM to return the true millivolts, not data scaled to the
/// internal voltage reference. Due to the possibility of a negative value, the raw
/// ADC reading should be checked first for bad channel parameters. If a bad parameter
/// is passed to this function, a value of zero will be returned, which might not be
/// otherwise determined to be an erroneous channel parameter versus a real voltage
/// reading of zero.
///
/// @param res channel for which to return measurement
///
/// @return channel voltage in millivolts
int16_t ADC_getResultMv(uint8_t res);


#endif /* ADC_H_ */