/* ////////////////////////////////////////////////////////////////////
 * EEPROM.c
 *
 *  Author: Eslam Aboutaleb
 /////////////////////////////////////////////////////////////////// */ 
#include "EEPROM.h"

void EEPROM_Init(void) {
	TWI_Init(); // just initialize the TWI module inside the MC
	SETBIT(DDRC,PC2);
}

uint8 EEPROM_Write_Byte(uint8 u8Dev_addr, uint16 u16Byte_addr,uint8 u8data) {
	TWI_Start();
	SETBIT(PORTC,PC2);
	if (TWI_Get_Status() != TW_START)
	return ERROR;

	//write the device address and R/W=0 (write)
	TWI_Write(u8Dev_addr);
	if (TWI_Get_Status() != TW_MT_SLA_W_ACK)
	return ERROR;

	//send the required first word location address
	TWI_Write((uint8) (u16Byte_addr >> 7));
	if (TWI_Get_Status() != TW_MT_DATA_ACK)
	return ERROR;
	//send the required second word location address
	TWI_Write((uint8) (u16Byte_addr));
	if (TWI_Get_Status() != TW_MT_DATA_ACK)
	return ERROR;
	//write byte to eeprom
	TWI_Write(u8data);
	if (TWI_Get_Status() != TW_MT_DATA_ACK)
	return ERROR;

	TWI_Stop();

	return SUCCESS;
}

uint8 EEPROM_Read_Byte(uint8 u8Dev_addr, uint16 u16Byte_addr,uint8 *u8data) {
	TWI_Start();
	clrBit(PORTC,PC2);
	if (TWI_Get_Status() != TW_START)
	return ERROR;

	//write the device address and R/W=0 (write)
	TWI_Write(u8Dev_addr);
	if (TWI_Get_Status() != TW_MT_SLA_W_ACK)
	return ERROR;

	//send the required first word location address
	TWI_Write((uint8) (u16Byte_addr >> 7));
	if (TWI_Get_Status() != TW_MT_DATA_ACK)
	return ERROR;
	//send the required second word location address
	TWI_Write((uint8) (u16Byte_addr));
	if (TWI_Get_Status() != TW_MT_DATA_ACK)
	return ERROR;

	//send a repeated start
	TWI_Start();
	if (TWI_Get_Status() != TW_REP_START)
	return ERROR;

	//write the device address and R/W=1 (Read)
	TWI_Write((u8Dev_addr)|1);
	if (TWI_Get_Status() != TW_MT_SLA_R_ACK)
	return ERROR;

	*u8data = TWI_Read_With_NACK();
	if (TWI_Get_Status() != TW_MR_DATA_NACK)
	return ERROR;

	TWI_Stop();
	return SUCCESS;
}
