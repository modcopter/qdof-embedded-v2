/*
* qdof_embedded_v2.cpp
*
* Created: 08.05.2013 19:41:00
*  Author: Simon
*/


#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <stdio.h>
#include "uart.h"

#include "data/DataModule.h"
#include "data/DataInput.h"
#include "data/DataOutput.h"

int stdio_putchar(char c, FILE *stream);
void update_led(char c);
static FILE uartout = {0};
	
class SerialPort : public DataModule {
	DataOutput<char> output;
	DataInput input;
	
	SerialPort() : input(this) {}
	
	
};

int main(void)
{
	uart_init(UART_BAUD_SELECT(19200, F_CPU));
	fdev_setup_stream (&uartout, stdio_putchar, NULL, _FDEV_SETUP_WRITE);
	stdout = &uartout;
	
	DDRB |= _BV(PORTB7);
	
	TCCR1B |= _BV(CS10);
	TIMSK1 |= _BV(TOIE1);
	
	sei();

	while (1);	
}

int stdio_putchar(char c, FILE *stream) {
	uart_putc(c);
	return 0;
}

ISR(TIMER1_OVF_vect) {
	
}