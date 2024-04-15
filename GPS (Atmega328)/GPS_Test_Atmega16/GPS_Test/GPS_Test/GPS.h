/*
 * GPS.h
 *
 * Created: 7/16/2023 3:44:53 PM
 *  Author: pc
 */ 


#ifndef GPS_H_
#define GPS_H_

#include <avr/io.h>
#include <util/delay.h>
#include "uart.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
unsigned char value,lati_value[15],longi_value[15],lati_dir,longi_dir;
char longi_degrees_str[3], longi_minutes_str[3],longi_decimal_str[5];
char lati_degrees_str[3], lati_minutes_str[3],lati_decimal_str[5];
double degrees,minutes,decimals,final_long,final_lat;


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
/*
	Description: This function extracts the longitude and latitude as NEMA format and them convert them as degrees format

*/
void GPS_Cordinates();

#endif /* GPS_H_ */