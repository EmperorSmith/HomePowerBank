/*
 * Serial.c
 *
 * Created: 7/20/2025 5:31:16 PM
 *  Author: Robert
 */


#include "HPB_lv_power_sys.h"
#include "serial.h"

uint8_t ser_buffer[SERIAL_BUF_SIZE];
int8_t ser_buf_index;						// denotes "end" of data to send
volatile uint8_t xmit_index;				// iterates through data to send

int USART_init()
{

	// variable init
	uint32_t i = 0;

	for(i = 0; i<SERIAL_BUF_SIZE; i++) ser_buffer[i] = 0;
	ser_buf_index = -1;
	xmit_index = 0;

	// configure serial port
	SERIAL_PORT.DIRSET = SERIAL_TX_PIN;
	SERIAL_PORT.OUTCLR = SERIAL_TX_PIN;

	// set baud rate; formula is f_cpu * k / baud
	i = ((F_CPU * 4) + (SERIAL_BAUD / 2)) / SERIAL_BAUD;     // under normal conditions, k=4

    // but BAUD needs >= 64, else double-rate mode is needed
    if (i < 64)
	{
		USART0.CTRLB = USART_RXMODE_CLK2X_gc;
		i = ((F_CPU * 8) + (SERIAL_BAUD / 2)) / SERIAL_BAUD; // for double-rate mode, k=8

	}

	USART0.BAUD = i;

	// enable transmitter, but do not enable interrupts yet (as there is no data to transmit)
	USART0.CTRLB |= USART_TXEN_bm;

    // if invalid baud rate available, signal as error
    if (i < 64) return 1;
    else return 0;

}


int USART_transmit(uint8_t *data)
{
	// return if not done with previous transmission (index will be set to negative number)
	if (ser_buf_index >= 0) return -1;

	// sanitize input variables
	if (data == 0) return -2;				// check null pointer

	// set indices ahead of copying
	ser_buf_index = 0;
	xmit_index = 0;

	// copy data to buffer, halt at max buffer size
	while (ser_buf_index < SERIAL_BUF_SIZE)
	{
        if (data[ser_buf_index] == 0) break;             // done if hit null value termination
		ser_buffer[ser_buf_index] = data[ser_buf_index];
		ser_buf_index++;

	}

    // if terminated immediately, reset index and return before initiating transmission
    if (ser_buf_index == 0)
    {
        xmit_index = -1;
        return 0;
    }

	// load first byte for transmission
	USART0.TXDATAL = ser_buffer[xmit_index];
	xmit_index++;

	// enable "need more data" interrupt; this should fire right away
	USART0.CTRLA = USART_DREIE_bm;

    // return number of characters copied
	return ser_buf_index;

}


ISR(USART0_DRE_vect)
{
    // check for "done" condition
	if (xmit_index < ser_buf_index)
	{
        // load next character to transmit
        USART0.TXDATAL = ser_buffer[xmit_index];
        xmit_index++;

	}
    else
    {
		// reset indices
		ser_buf_index = -1;
		xmit_index = 0;

		// no more interrupts until next transmission
		USART0.CTRLA &= (~USART_DREIE_bm);
    }



}