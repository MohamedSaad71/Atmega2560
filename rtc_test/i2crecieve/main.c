/*
 * rtcproject.c
 *
 * Created: 6/26/2023 11:09:32 AM
 * Author : pc
 */ 
#include "UART.h"
#include <avr/io.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <util/delay.h>
#include "twi.h"
#include "RTC1307.h"
#include "lcd.h"





int main(void)
{
	char buffer[25];
	uint8 data = 'b';
	
	TWI_init();
	TWI_start();
	UART0_init();
	
	
    /* Replace with your application code */
    while (1) 
    {
		
		//UART0_Send(data);
		RTC_Read_Clock(0);							/* Read the clock with second address i.e location is 0 */
				if (hour & TimeFormat12)
				{
					sprintf(buffer, "%02x:%02x:%02x  ", (hour & 0b00011111), minute, second);
					
					if(IsItPM(hour))
					strcat(buffer, "PM");
					else
					strcat(buffer, "AM");
					
					_delay_ms(100);
				}
				
				else
				{
					sprintf(buffer, "%02x:%02x:%02x  ", (hour & 0b00011111), minute, second);
					LCD_moveCursor(1,1);
					UART0_sendString(buffer);
						
					
					
					//UART0_Send(buffer[8]);
				}
				RTC_Read_Calendar(3);						/* Read the calender with day address i.e location is 3 */
				sprintf(buffer, "%02x/%02x/%02x ", date, month, year);
				LCD_moveCursor(4,4);
				UART0_sendString(buffer);
				_delay_ms(100 ) ;
		  }
}


