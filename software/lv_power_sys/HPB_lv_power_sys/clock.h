/*
 * clock.h
 *
 * Created: 8/20/2025 10:20:48 PM
 *  Author: Robert
 */


#ifndef CLOCK_H_
#define CLOCK_H_

#include <avr/interrupt.h>
#include <avr/io.h>

/// Initializes the system oscillators, RTC, and timer.
///
/// This function sets up the main oscillator to max speed, configures the RTC
/// to count time ticks, and pre-configures a Timer A block to serve as a delay
/// function. The RTC tick time is determined by a #define in the header file.
///
/// @returns 0 if success, else if fail
int CLOCK_init();


/// Returns the system tick count since bootup.
///
/// This function returns the current time, in ticks, since the RTC
/// started running on initial bootup.
///
/// @returns system tick time since bootup
uint32_t CLOCK_getTime();


/// Delay execution by a certain amount.
///
/// This function ties up the CPU for a specific amount of time. It simply
/// loops over and over, waiting for the interrupt flag to assert. It does
/// not use sleep mode or actual interrupts, allowing for background operations
/// like ADC measurements or extended communication. It returns the actual
/// amount of time delayed.
///
/// @param requested delay, in milliseconds
///
/// @returns actual time delayed, in milliseconds
uint16_t CLOCK_delayMSec(uint16_t delay);




#endif /* CLOCK_H_ */