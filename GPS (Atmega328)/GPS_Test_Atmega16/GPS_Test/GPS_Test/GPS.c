/*
 * GPS.c
 *
 * Created: 7/16/2023 3:50:30 PM
 *  Author: pc
 */ 

#include "GPS.h"
#include "lcd_lib.h"

int i=0;
void GPS_Cordinates()
{
	
	
	value=usart_getch();
	
	
	if(value=='$')
	{
		
		value=usart_getch();


		
		if(value=='G')
		{
			
			value=usart_getch();

			if(value=='P')
			{
				
				
				
				value=usart_getch();

				if(value=='G')
				{
					
					value=usart_getch();

					
					if(value=='G')
					{
						
						value=usart_getch();
						
						if(value=='A')
						{
							
							value=usart_getch();
							
							
							if(value==',')
							{
								
								while(value!=',')
								{
									value=usart_getch();
									
								}
								lati_value[0]=usart_getch();
								
								value=lati_value[0];
								
								for(i=1;value!=',';i++)
								{
									lati_value[i]=usart_getch();
									
									value=lati_value[i];
									
								}
								
								
								value=usart_getch();
								if(value == ',')
								{
									while(value == ',')
									{
										value=usart_getch();
										
									}
									
								}
								longi_value[0]=value;
								
								longi_value[1]=usart_getch();
								value=longi_value[1];
								for(i=2;value!=',';i++)
								{
									longi_value[i]=usart_getch();
									value=longi_value[i];
								}
								
								


/*
//  								for( int j=0;j<9;j++)
//  								{
//  									LCDGotoXY(j,1);
//  									LCDsendChar(longi_value[j]);
//  									
//  								}
*/

								/*Extracting the latitude and convert it to degrees format*/
								
								
								/*Extracting the longitude and convert it to degrees*/

								strncpy(longi_degrees_str,longi_value , 2);
 								longi_degrees_str[2] = '\0';
 								strncpy(longi_minutes_str,longi_value + 2, 2);
 								longi_minutes_str[2] = '\0';
 								strncpy(longi_decimal_str,longi_value + 5, 4);
 								longi_decimal_str[5] = '\0';
 								degrees=atoi(longi_degrees_str);
 								minutes=atoi(longi_minutes_str);
 								decimals=atoi(longi_decimal_str);
								
 								double D=decimals/10000;
 								double r=(minutes/60)+D;
 								double g=(double)degrees+r;
 								
 								final_long =g;
 								LCDGotoXY(1,1);
 								LCDstring(longi_minutes_str);
 								
 								strncpy(lati_degrees_str,lati_value , 3);
 								lati_degrees_str[3] = '\0';
 								strncpy(lati_minutes_str,lati_value + 3, 3);
 								lati_minutes_str[3] = '\0';
 								strncpy(lati_decimal_str,lati_value + 7, 2);
 								lati_decimal_str[3] = '\0';
 								degrees=atoi(lati_degrees_str);
 								minutes=atoi(lati_minutes_str);
 								decimals=atoi(lati_decimal_str);
 								 D=(double)decimals/100000/60;
 								 r=(double)minutes/60;
								 g= r+D;
 								
 								final_lat =(double)degrees+g;

								
								
							}
						}
					}
				}
			}
		}
	}
}