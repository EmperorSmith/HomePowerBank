/*
 * HPB_lv_power_sys.c
 *
 * Created: 8/20/2025 10:01:49 PM
 * Author : Robert
 */


#include "HPB_lv_power_sys.h"

#define DBG_LEN 30
char dbg_line[DBG_LEN];


int main(void)
{

	state = BOOTUP;
	status = 0;

	int flags = 0;

	// reuse var for initializing string array
	for (flags = 0; flags < DBG_LEN; flags++) dbg_line[flags] = 0;
	flags = 0;

	// set up digital I/O
	SYS_LED_PORT.DIRSET = (1 << SYS_LED_PIN);
	SYS_LED_PORT.OUTSET = (1 << SYS_LED_PIN);

	PWR_LED_PORT.DIRSET = (1 << PWR_LED_PIN);
	PWR_LED_PORT.OUTCLR = (1 << PWR_LED_PIN);

	USR_LED_PORT.DIRSET = (1 << USR_LED_PIN);
	USR_LED_PORT.OUTCLR = (1 << USR_LED_PIN);

	USR_SW_PORT.DIRCLR = (1 << USR_SW_PIN);
	USR_SW_PORT.USR_SW_PINCTRL = PORT_PULLUPEN_bm;


	// cannot send info out debug port, but can watch variable when debugging
    flags = CLOCK_init();
	flags = USART_init();

	sei();		// enable interrupts (needed for USART transmission)

	// debug line
	sprintf(dbg_line,"\n\nInitializing...\n\0");
	flags = USART_transmit(dbg_line);

	CLOCK_delayMSec(2);

	// init ADC, send debug message
	flags = ADC_init();
	if (flags) sprintf(dbg_line,"ADC - Done\n\0");
	else sprintf(dbg_line,"ADC - Error\n\0");
	flags = USART_transmit(dbg_line);

	CLOCK_delayMSec(2);

	// kick off first conversion
	flags = ADC_startSweep();
	if (flags)
	{
		sprintf(dbg_line,"\nERROR running ADC\n\0");
		flags = USART_transmit(dbg_line);
	}

	state = IDLE;
	SYS_LED_PORT.OUTCLR = (1 << SYS_LED_PIN);

    while (1)
    {

		// get button status


		switch (state)
		{
			case IDLE:

				break;

			case SRC:

				break;

			case SINK:

				break;

			case HV_T_CHG:

				break;

			case CHG_CELL:

				break;

			case FAULT:

				break;

		}


		// start ADC sweep, loop until ADC is done, then sleep until next RTC tick

		ADC_startSweep();

		flags = ADC_isDone();

		while (flags == 0) flags = ADC_isDone();


    }
}

