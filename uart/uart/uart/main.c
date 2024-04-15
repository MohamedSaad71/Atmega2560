/*
 * uart.c
 *
 * Created: 7/4/2023 11:49:25 AM
 * Author : pc
 */ 

#include <avr/io.h>
#include "uart.h"


#define Baud_Rate 9600

#define MC2_READY 0x10


int main(void)
{
    UART0_init();
	uint8 data = 'b';
	//while(UART0_ReceiveData() != MC2_READY){}
	
	
    while (1) 
    {
		UART0_sendString("Hello");
		
    }
}

