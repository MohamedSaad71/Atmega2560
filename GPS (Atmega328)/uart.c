/*
 * uart.c
 *
 * Created: 7/16/2023 3:49:09 PM
 *  Author: pc
 */ 
#include <avr/io.h>
#include "uart.h"

void usart_init()
{

	UCSRB |= (1<<RXCIE) | (1 << RXEN) | (1 << TXEN);
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);

	UBRRL = BAUD_PRESCALE;
	UBRRH = (BAUD_PRESCALE >> 8);
}

unsigned int usart_getch()
{

	while ((UCSRA & (1 << RXC)) == 0);
	return(UDR);
}