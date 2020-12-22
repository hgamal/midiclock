#include <avr/io.h>
#include <avr/interrupt.h>

#include "uart.h"

/*
ISR(USART1_RX_vect)
{
    char ReceivedByte;
    ReceivedByte = UDR1; // Fetch the received byte value into the variable " ByteReceived "
    UDR1 = ReceivedByte; // Echo back the received byte back to the computer
}
*/

void uart_init(int baud)
{
    DDRD &= ~_BV(PD2);
    DDRD |= _BV(PD3);

    int ubrr = F_CPU / 16 / baud - 1;
    UBRR1H = (unsigned char) (ubrr>>8);
    UBRR1L = (unsigned char) ubrr;

    /* 
	Set Frame Format
	    Asynchronous mode
	    No Parity
	    1 StopBit
	    char size 8
    */
    UCSR1C = (3<<UCSZ10);

    //Enable The receiver and transmitter
    UCSR1B = (1<<RXEN1)|(1<<TXEN1)|(1<<RXCIE1);

	UDR1;
}

void uart_putchar(char data)
{
    /* Wait for empty transmit buffer */
    while ( !( UCSR1A & (1<<UDRE1)) )
		;

    /* Put data into buffer, sends the data */
    UDR1 = data;
}

int uart_putchar_ready()
{
    /* Wait for empty transmit buffer */
    return UCSR1A & (1<<UDRE1);
}

int uart_getchar( void )
{
    /* Wait for data to be received */
    while ( !(UCSR1A & (1<<RXC1)) )
	    ;

    /* Get and return received data from buffer */
    return UDR1;
}

int uart_getchar_ready()
{
	return (UCSR1A & (1<<RXC1));
}
