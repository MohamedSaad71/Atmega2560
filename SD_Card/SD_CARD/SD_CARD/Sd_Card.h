/*
 * Sd_Card.h
 *
 * Created: 7/17/2023 2:56:49 PM
 *  Author: Mohamed Saad
 *
 */ 


#ifndef SD_CARD_H_
#define SD_CARD_H_


#define SD_CS_PIN 10

typedef enum
 {
	 false, true
  } bool;

/***************************************************************************
*
*                         Functions Prototypes
*
****************************************************************************/


void SD_init();
unsigned char SD_Read_Block(uint32_t block_addr, uint8_t *buffer);
unsigned char SD_Write_Block(uint32_t block_addr, uint8_t *buffer);

#endif /* SD_CARD_H_ */