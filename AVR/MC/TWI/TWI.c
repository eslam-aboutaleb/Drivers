/* ///////////////////////////////////////////////////////////////////////////
 *
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TWI.h"
#include "MathFuncs.h"
#include "TWI_private.h"
  
static uint8 Prescaler_global;

/*Local functions prototypes*/
static void TWI_Prescaler_Num(TWI_Prescaler Prescaler);
static void TWI_Genral_Call_State(TWI_Genral_Call_Bit GCALL_Bit);
static void TWI_SetMode(TWI_Speed_Mode Mode);
static void TWI_EnBus(void);
static void TWI_Set_ACK_Bit(TWI_ACK_Bit ACK);

void TWI_Init(TWi_Typedef * TWI_ConfigPtr)
{
	TWAR |= ((TWI_ConfigPtr->Address)<<1);
	TWI_Prescaler_Num(TWI_ConfigPtr->Prescaler);
	TWI_Interrupt(TWI_ConfigPtr->Interrupt_EN_DIS);
	TWI_Genral_Call_State(TWI_ConfigPtr->GCALL_BIT);
	TWI_SetMode(TWI_ConfigPtr->Mode);
	TWI_Set_ACK_Bit(TWI_ConfigPtr->ACK);
}

static void TWI_Set_ACK_Bit(TWI_ACK_Bit ACK)
{
	switch(ACK)
	{
		case Enable_ACK_Bit:
		TWCR = (1<<TWEN)|(1<<TWEA);
		break;
		case Disable_ACK_Bit:
		TWCR = (1<<TWEN);
		break;
		default:
		break;
	}
}



static void TWI_SetMode(TWI_Speed_Mode Mode)
{
	switch(Mode)
	{
		case Standard_Mode:
		TWBR=(uint8)(((F_CPU/TWI_NORMAL_MODE)-16)/2*PWR(4,Prescaler_global));
		break;
		case Fast_mode:
		TWBR=(uint8)(((F_CPU/TWI_FAST_MODE)-16)/2*PWR(4,Prescaler_global));
		break;
		default:
		break;
	}
}




void TWI_Interrupt(TWI_Interrupt_Mode Interrupt_EN_DIS)
{
	switch (Interrupt_EN_DIS)
	{
		case Enable_Interrupt:
		SET_BIT(TWCR,TWIE);
		break;
		case Disable_Interrupt:
		CLEAR_BIT(TWCR,TWIE);
		break;
	}
}


uint8 TWI_Start(void)
{
	/*reset TWI control register*/
	TWCR = 0;
	
	/*TWEN must be written to one to enable the Two-wire Serial Interface, TWSTA must be written to
	one to transmit a START condition and TWINT must be set to clear the TWINT Flag.               */
	TWCR= (1<<TWEN)|(1<<TWSTA)|(1<<TWINT);
	
	/*Wait until flag is set*/
	while(BIT_IS_CLEAR(TWCR,TWINT));
	
	
	if (TWI_Get_Status()!=TWI_START)
	{
		return 0;
	}
	
	return 1;
}



uint8 TWI_Repeated_start(void)
{
	/*Repeated START:
	enables the master to switch between slaves, Master Transmitter mode and Master Receiver
	mode without losing control over the bus */
	TWI_Start();
	
	if (TWI_Get_Status() != TWI_REP_START)
	{
		return 0;
	}
	
	return 1;
}



void TWI_Clear_Flag(void)
{
	SET_BIT(TWCR,TWINT);
	
	/*Wait until flag is set*/
	while(BIT_IS_CLEAR(TWCR,TWINT));
}


void TWI_Stop(void)
{
	/*reset TWI control register*/
	TWCR = 0;
	TWCR= (1<<TWEN)|(1<<TWSTO)|(1<<TWINT);
	
}



static void TWI_Genral_Call_State(TWI_Genral_Call_Bit GCALL_Bit)
{
	/*Transmitting the general call address followed by a Read bit is meaningless*/
	/*It is used to send the same message to several slaves */
	switch(GCALL_Bit)
	{
		case Disable_G_Call_Bit:
		CLEAR_BIT(TWAR,TWGCE);
		break;
		case Enable_G_Call_Bit:
		SET_BIT(TWAR,TWGCE);
		break;
		default:
		     /* NO Action */
		break;
	}
}




void TWI_Enable(TWI_state State)
{
	switch(State)
	{
		case Enable_TWI:
		SET_BIT(TWCR,TWEN);
		break;
		case Disable_TWI:
		CLEAR_BIT(TWCR,TWEN);
		break;
		default:
		break;
	}
}




static void TWI_Prescaler_Num(TWI_Prescaler Prescaler)
{
	switch(Prescaler)
	{
		case Prescaler_1:
		CLEAR_BIT(TWSR,TWPS0);
		CLEAR_BIT(TWSR,TWPS1);
		Prescaler_global=1;
		break;
		case Prescaler_4:
		SET_BIT(TWSR,TWPS0);
		CLEAR_BIT(TWSR,TWPS1);
		Prescaler_global=4;
		break;
		case Prescaler_16:
		CLEAR_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
		Prescaler_global=16;
		break;
		case Prescaler_64:
		SET_BIT(TWSR,TWPS0);
		SET_BIT(TWSR,TWPS1);
		Prescaler_global=64;
		break;
		default:
		         /*No Action*/
		break;
		
	}
}



uint8 TWI_Get_Status(void)
{
	/* Read 7:3 (TWS bits */ 
	return TWSR & 0xF8;
}



uint8 TWI_Read_ACK(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(BIT_IS_CLEAR(TWCR,TWINT));
	
	if (TWI_Get_Status()==TWI_MR_DATA_ACK)
	{
		return TWDR;
	}
	else
	{
		return 0;
	}
	
}



uint8 TWI_Read_NACK(void)
{
	TWI_EnBus();
	return TWDR;
}

static void TWI_EnBus(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(BIT_IS_CLEAR(TWCR,TWINT));
}

void TWI_SendAddress(uint8 Address ,TWi_RW_Commands R_W)
{
	/*Assign address +Read/write Data command */
	TWDR=(Address)+R_W;
	TWI_EnBus();
	while(TWI_Get_Status() !=TWI_MT_SLA_W_ACK);

}

uint8 TWI_SendByte(uint8 Data)
{
	/*Assign data to TWDR reg*/
	TWDR=Data;
	TWI_EnBus();
	if(TWI_Get_Status() !=TWI_MT_DATA_ACK)
	{
		return 0;
	}
	return 1;
}


void TWI_SendString(uint8 *str)
{
	//= while (*str>0)
	while(*str!='\0')
	{
		TWI_SendByte(*str);
		str++;
	}
	str++; //because str didn't increased the last time
	//because condition !=0 terminated it
	TWI_SendByte('\0');
}

void TWI_getstring_NACK(uint8 *str){
	unsigned char temp = 0;
	do
	{
		temp = TWI_Read_NACK();
		*str = temp;
		str++;
	}while(temp != '\0');
}
void TWI_getstring_ACK(uint8 *str){
	unsigned char temp = 0;
	do
	{
		temp = TWI_Read_ACK();
		*str = temp;
		str++;
	}while(temp != '\0');
}
