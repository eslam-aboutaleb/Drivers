/* ///////////////////////////////////////////////////////////////////////////
 *
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#ifndef TWI_H_
#define TWI_H_

typedef enum
{
	Disable_G_Call_Bit,
	Enable_G_Call_Bit
}TWI_Genral_Call_Bit;

typedef enum
{
	Disable_ACK_Bit,
	Enable_ACK_Bit
}TWI_ACK_Bit;

typedef enum
{
	Disable_TWI,
	Enable_TWI
}TWI_state;

typedef enum
{
	Disable_Interrupt,
	Enable_Interrupt
}TWI_Interrupt_Mode;

typedef enum
{
	Prescaler_1,
	Prescaler_4,
	Prescaler_16,
	Prescaler_64
}TWI_Prescaler;

typedef enum
{
	Standard_Mode,
	Fast_mode
}TWI_Speed_Mode;

typedef enum
{
    TWI_READ     =     0x01,
    TWI_WRITE    =    0x00
}TWi_RW_Commands;

typedef struct
{
	uint8 Address;
	TWI_Prescaler Prescaler;
	TWI_Genral_Call_Bit GCALL_BIT;
	TWI_Interrupt_Mode Interrupt_EN_DIS;
	TWI_Speed_Mode Mode;
	TWI_ACK_Bit ACK;
	
}TWi_Typedef;

void TWI_Init(TWi_Typedef * TWI_ConfigPtr);
void TWI_Interrupt(TWI_Interrupt_Mode Interrupt_EN_DIS);
void TWI_Enable(TWI_state State);
uint8 TWI_Get_Status(void);
uint8 TWI_Start(void);
uint8 TWI_Repeated_start(void);
void TWI_Clear_Flag(void);
void TWI_SendAddress(uint8 Address ,TWi_RW_Commands R_W);
void TWI_Stop(void);
uint8 TWI_Read_ACK(void);
uint8 TWI_Read_NACK(void);
void TWI_getstring_NACK(uint8 *str);
void TWI_getstring_ACK(uint8 *str);
uint8 TWI_SendByte(uint8 Data);
void TWI_SendString(uint8 *str);

#endif /* TWI_H_ */