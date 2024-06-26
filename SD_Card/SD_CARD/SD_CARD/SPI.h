

#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include "MemMap.h"
#include "common_macros.h"
#include "std_types.h"

typedef enum{
	MASTER,
	SLAVE
	
}SPIMode_type;




void SPI_Init(SPIMode_type mode);

uint8 SPI_SendReceive(uint8 data);
uint8 SPI_ReceivePerodic(uint8*pdata);
void SPI_SendNoBlock(uint8 data);
uint8 SPI_ReceiveNoBlock(void);

void SPI_InterruptEnable(void);
void SPI_SetCallBack(void(*localptr)(void));



#endif /* SPI_H_ */