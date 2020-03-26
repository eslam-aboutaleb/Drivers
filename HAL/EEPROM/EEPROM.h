/*
 * EEPROM.h
 *
 *  Author: Eslam Aboutaleb
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "I2C.h"


#define ERROR 0
#define SUCCESS 1


void EEPROM_Init(void);
uint8 EEPROM_Write_Byte(uint8 u8Dev_addr, unsigned short u16Byte_addr,
uint8 u8data);
uint8 EEPROM_Read_Byte(uint8 u8Dev_addr, unsigned short u16Byte_addr,
uint8 *u8data);

#endif /* EEPROM_H_ */