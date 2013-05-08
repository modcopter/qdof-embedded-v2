/*
 * qdof_embedded_v2.cpp
 *
 * Created: 08.05.2013 19:41:00
 *  Author: Simon
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "uart.h"

int main(void)
{
	uart_init(UART_BAUD_SELECT(19200, F_CPU));
	sei();
	
	uart_puts("Hallo Welt!");
	
    while(1) {
		
    }
}