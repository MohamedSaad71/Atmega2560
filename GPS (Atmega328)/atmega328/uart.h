/*
 * uart.h
 *
 * Created: 7/16/2023 3:48:56 PM
 *  Author: pc
 */ 


#ifndef UART_H_
#define UART_H_

#define F_CPU 8000000UL

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 16UL))) - 1)

void usart_init();
unsigned int usart_getch();



#endif /* UART_H_ */