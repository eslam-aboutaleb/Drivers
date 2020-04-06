/* ///////////////////////////////////////////////////////////////////////////
 *
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <string.h>
#include "TWI.h"
#include "EX_EEPROM.h"

static uint8 EX_EEPROM_ADDRESS;
/*Global variable to access the last section has been written to*/
uint16 LastUsedSection;

#define EX_EEPROM_SET_A0_A1_A2_BITS(A0,A1,A2)    (EX_EEPROM_BASE_ADDRESS|((A0==1)?0x02:0x00)|((A1==1)?0x04:0x00)|((A2==1)?0x08:0x00))

void  EX_EEPROM_Init(uint8 A0_State,uint8 A1_State,uint8 A2_State)
{
	TWi_Typedef *TWi_Ptr=(void*)0;
	TWi_Ptr->ACK=Enable_ACK_Bit;
	TWi_Ptr->Address=MCU_ADDRESS;
	TWi_Ptr->GCALL_BIT=Disable_G_Call_Bit;
	TWi_Ptr->Interrupt_EN_DIS=Disable_Interrupt;
	TWi_Ptr->Mode=Standard_Mode;
	TWi_Ptr->Prescaler=Prescaler_1;
	
	TWI_Init(TWi_Ptr);
	
	EX_EEPROM_ADDRESS=EX_EEPROM_SET_A0_A1_A2_BITS(A0_State,A1_State,A2_State);
	
}

void EX_EEPROM_ReadByte(uint8 *R_Data,uint8 Section)
{
	TWI_Start();
	TWI_SendAddress(EX_EEPROM_ADDRESS,TWI_WRITE);
	TWI_SendByte(Section);
	TWI_Repeated_start();
	TWI_SendAddress(EX_EEPROM_ADDRESS,TWI_READ);
	*R_Data=TWI_Read_NACK();
	TWI_Stop();
	
}
void EX_EEPROM_WriteByte(uint8 Data,uint8 Section)
{
	TWI_Start();
	TWI_SendAddress(EX_EEPROM_ADDRESS,TWI_WRITE);
	TWI_SendByte(Section);
	TWI_SendByte(Data);
	TWI_Stop();
	
	LastUsedSection=Section;
}

void EX_EEPROM_ReadBlocks(uint8 Section, uint8 *DataBuffer,uint8 N_Blocks)
{
	uint16 index=0;
	uint8 Read;
	for (index=0;index<N_Blocks;index++)
	{
		EX_EEPROM_ReadByte(&Read,Section+index);
		DataBuffer[index]=Read;
	}
	DataBuffer[index]='\0';
	
	LastUsedSection=index;
}

void EX_EEPROM_WriteBlocks(uint8 Section, uint8 *DataBuffer)
{
	uint16 index=0;
	uint8 Write;
	for (index=0;DataBuffer[index]!='\0';index++)
	{
		Write=DataBuffer[index];
		EX_EEPROM_WriteByte(Write,Section+index);
	}
	EX_EEPROM_WriteByte('\0',Section+index);
	
	LastUsedSection=index;
}