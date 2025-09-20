/*
 * HPB_lv_power_sys.h
 *
 * Created: 8/20/2025 10:09:16 PM
 *  Author: Robert
 */


#ifndef HPB_LV_POWER_SYS_H_
#define HPB_LV_POWER_SYS_H_

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/eeprom.h>
#include <stdio.h>

// --- clocking / timing information ---

#define F_CPU 5000000

#define CLK_TICK_RATE 10

#define USB_SRC_TIMEOUT (4*60*60*CLK_TICK_RATE)		// set timeout for when USB sourcing automatically shuts off, in internal clock ticks

uint32_t usb_src_timeout_alarm;						// alarm variable for USB sourcing timeout

// --- state and status ---

uint8_t state;

enum lv_sys_state
{
	BOOTUP,			// initial boot-up state
	IDLE,			// idle state, nothing happening
	SRC,			// sourcing power to USB port
	SINK,			// sinking power from USB port
	HV_T_CHG,		// trickle-charging HV from USB port
	CHG_CELL,		// sourcing power from HV to recharge battery cell
	FAULT			// latched fault state, requires system reset

};

uint8_t status;

#define LVSYS_STATUS_CELL_LO_bmsk	// is the backup cell voltage low? 1 = yes, 0 = no
#define LVSYS_STATUS_CELL_LO_bpos

#define LVSYS_STATUS_HVEN_bmsk		// is the HV interface enabled? 1 = yes, 0 = no
#define LVSYS_STATUS_HVEN_bpos

#define LVSYS_STATUS_5VDET_bmsk		// does the USB BUS have voltage on it? 1 = yes, 0 = no
#define LVSYS_STATUS_5VDET_bpos

#define LVSYS_STATUS_CCDIR_bmsk		// CC pin direction, 0 for pulldown, 1 for pullup
#define LVSYS_STATUS_CCDIR_bpos

#define LVSYS_STATUS_CCDET_bmsk		// is external CC pin connection detected? 1 = yes, 0 = no
#define LVSYS_STATUS_CCDET_bpos

#define LVSYS_STATUS_BTN_bmsk		// user interface button state, 1 = pressed, 0 = not pressed
#define LVSYS_STATUS_BTN_bpos

#define LVSYS_STATUS__bmsk			// dummy bit
#define LVSYS_STATUS__bpos

// --- voltage thresholds ---

#define CELL_LO_THR_MV 3100
#define CELL_NOT_LOW_THR_MV 3400
#define CELL_HI_THR_MV 4250

#define CCPIN_LVL1_MV 420			// CC pin level : 0.5/0.9A sink/source current
#define CCPIN_LVL2_MV 940			// CC pin level : 1.5A sink/source current
#define CCPIN_LVL3_MV 1690			// CC pin level : 3A sink/source current
#define CCPIN_TOL_MV 200			// tolerance (pos and neg) on cc pin levels

#define VBUS_THR_MV 4250

enum ADC_CH_NAME
{
	AI_BUS,
	AI_CC1,
	AI_CC2,
	AI_CELL,
	AI_SUP
};

// ----- ports and pins -----

#define USR_SW_PORT PORTA		// user interface button
#define USR_SW_PIN 5
#define USR_SW_PINCTRL PIN5CTRL

#define USR_LED_PORT PORTA		// user interface LED
#define USR_LED_PIN 3

#define PWR_LED_PORT PORTC		// board-level power status
#define PWR_LED_PIN 4

#define SYS_LED_PORT PORTC		// board-level system activity
#define SYS_LED_PIN 5

#define LED_SLOW_RATE 20		// LED slow blink rate
#define LED_FAST_RATE 5			// LED fast blink rate

#endif /* HPB_LV_POWER_SYS_H_ */