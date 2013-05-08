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
static FILE uartout = {0};

class LedModule : public DataModule {
	public:
	DataInput inp;
	LedModule() : inp(this) {}
	
	void update(void *data) {
		char state = *(char *)(data);
		uart_putc(state);
		//
		if (state)
		PORTB |= _BV(PORTB7);
		else
		PORTB &= ~_BV(PORTB7);
	}
};

template <class T>
class NotModule : public DataModule {
	public:
	DataInput inp;
	DataOutput<T> out;
	NotModule() : inp(this) {}
	
	void update(void *data) {
		T temp = *(T *)(data);
		out = compl temp;
	}
};

int main(void)
{
	uart_init(UART_BAUD_SELECT(19200, F_CPU));
	fdev_setup_stream (&uartout, stdio_putchar, NULL, _FDEV_SETUP_WRITE);
	stdout = &uartout;
	sei();
	
	DDRB |= _BV(PORTB7);
	
	NotModule<char> mod;
	LedModule led;
	DataOutput<char> out;
	
	out > mod.inp;
	mod.out > led.inp;
	
	while(1) {
		uint16_t c = uart_getc();
		if ((c & 0xFF00) == 0) {
			out = c;
		}
	}
}

int stdio_putchar(char c, FILE *stream) {
	uart_putc(c);
	return 0;
}