/*
 * clock.c
 *
 * Created: 7/6/2025 5:17:02 PM
 *  Author: Robert
 */

#include "HPB_lv_power_sys.h"
#include "clock.h"

uint16_t max_delay;
uint32_t sys_time;
uint16_t delay_ticks_per_msec;


int CLOCK_init()
{
	sys_time = 0;

	// set oscillator to quarter speed (5MHz)
	CCP = CCP_IOREG_gc;
	CLKCTRL.MCLKCTRLB = CLKCTRL_PDIV_4X_gc | CLKCTRL_PEN_bm;

	// run low-power 32k osc always
	CCP = CCP_IOREG_gc;
	CLKCTRL.OSC32KCTRLA = CLKCTRL_RUNSTDBY_bm;

	// set up RTC
	RTC.PER = ((32768 + (CLK_TICK_RATE/2) ) / CLK_TICK_RATE);	// set RTC period based on tick rate
	RTC.INTCTRL = RTC_OVF_bm;									// interrupt on overflow
	RTC.CLKSEL = RTC_CLKSEL_INT32K_gc;							// internal 32k oscillator; should be this by default...
	RTC.CTRLA = RTC_RUNSTDBY_bm | RTC_RTCEN_bm;					// run in standby, enable RTC

	// set up Timer A for producing blocking delays
	delay_ticks_per_msec = ((F_CPU / 16) + 500) / (1000);

	max_delay = 65535 / delay_ticks_per_msec;
	if (max_delay == 0) max_delay = 1;

	TCA0_SINGLE_CTRLA = TCA_SINGLE_CLKSEL_DIV16_gc;	// large divider; reduces resolution, but expands range

	return 0;
}



uint32_t CLOCK_getTime()
{
	return sys_time;
}


uint16_t CLOCK_delayMSec(uint16_t delay)
{
	uint16_t time = 0;

	if (delay > max_delay) time = max_delay;
	else time = delay;

	time *= delay_ticks_per_msec;

	TCA0_SINGLE_PER = time;						// load target delay tick time
	TCA0_SINGLE_CNT = 0;						// reset count (just in case)
	TCA0_SINGLE_CTRLA |= TCA_SINGLE_ENABLE_bm;	// enable time

	time = 1;			// reuse variable as flag
	while (time)		// idle until overflow flag is set
	{
		if (TCA0_SINGLE_INTFLAGS & TCA_SINGLE_OVF_bm) time = 0;
	}

	TCA0.SINGLE.INTFLAGS = TCA_SINGLE_OVF_bm;		// clear overflow flag
	TCA0_SINGLE_CTRLA &= ~(TCA_SINGLE_ENABLE_bm);	// disable timer

	// return
	if (delay > max_delay) return max_delay;

	return delay;
}


/// Interrupt routine for RTC.
///
/// This is the interrupt service routine for the RTC. All it does is
/// increment the system tick time and clear the interrupt flag.
ISR(RTC_CNT_vect)
{
	sys_time++;						// increment tick time
	RTC.INTFLAGS = RTC_OVF_bm;		// clear interrupt flag
}
