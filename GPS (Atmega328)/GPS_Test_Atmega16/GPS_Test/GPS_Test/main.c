
#include <avr/io.h>
#include <util/delay.h>
#include "lcd_lib.h"
#include "GPS.h"
#include "uart.h"





char  myString[10];

int main(void)
{
	
	LCDinit();
	
	LCDGotoXY(0,0);
	LCDstring(" GPS... ");
	
	usart_init();

	
	while(1)
	{
		int i=0;
		while(i<20)
		{
			GPS_Cordinates();
			i++;
		}



		LCDclr();
		dtostrf(final_long, 5, 6, myString);
		
		LCDGotoXY(1,0);
		LCDstring(" Long:");
		LCDstring(myString);
		
		
		dtostrf(final_lat, 5, 6, myString);
		
		LCDGotoXY(1,1);
		LCDstring("Lat:");
		LCDstring(myString);


	}
}





