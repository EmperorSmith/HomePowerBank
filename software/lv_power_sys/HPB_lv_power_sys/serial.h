#include <avr/interrupt.h>
#include <avr/io.h>

#define SERIAL_BAUD 230400
#define SERIAL_BUF_SIZE 32
#define SERIAL_TX_PIN 0x04;
#define SERIAL_PORT PORTB

/// Set up UART port
///
/// This function configures the UART port to send messages out.
/// It does not acknowledge or handle any transmissions received.
/// The Tx pin, pin port, baud rate, and buffer size are all #defined
/// in the header file. The function will attempt to achieve the
/// requested baud rate, signalling an error if it cannot be achieved.
///
/// @return 0 for success, 1 for bad baud rate, else general failure
int USART_init();


/// Transmit data from UART port
///
/// This function takes in a series of characters (uint8 type) to send
/// out the UART port. It copies the included data into an internal buffer,
/// so the passed data does not need to persist beyond the function call.
/// The data passed in is copied until either (a) a null character is read
/// (in keeping with C-style string termination), or (b) the maximum internal
/// buffer size is reached. (This prevents buffer overflows.) The system is
/// interrupt-driven. It will drop data if it is still sending a previously-
/// passed string.
///
/// @param data a pointer to array of bytes to send, null-terminated
///
/// @return -1 for transmission rejected, else number of characters copied
int USART_transmit(uint8_t* data);