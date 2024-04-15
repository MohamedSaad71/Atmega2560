
#include "UART.h"
#include <stdio.h>
#include <util/delay.h>
#include "lcd.h"


#define MC2_READY 0x10

int main() {
	UART0_init();
	LCD_init();
	
	char str[15];
	
	
	//LCD_displayCharacter(str[0]);
	while(1)
	{
		
		
		UART0_receiveString(str);
		LCD_moveCursor(2,0);
		LCD_displayString(str);
		//LCD_intgerToString(i);
		
		//LCD_displayCharacter(UART0_ReceiveData());
		
	}
	
	return 0;
}