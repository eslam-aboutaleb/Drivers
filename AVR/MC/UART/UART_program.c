/*
 * UART_program.c
 *
 * Created: 2/12/2020 1:24:27 PM
 *  Author: Author: Eslam Aboutaleb
 */ 
#include "UART_interface.h"

void UART_init(UART_configType * configType_PTr)
{
	uint16 BaudRate=configType_PTr->BaudRate;
	uint32 BaudRate_equ=0;
	/*set URSEL bit to write on UCSRC register*/
	SET_BIT(UCSRC,URSEL);
	
	switch(configType_PTr->Mode)
	{
		case Asynchronous:
		CLEAR_BIT(UCSRC,UMSEL);
		break;
		case Synchronous:
		SET_BIT(UCSRC,UMSEL);
		break;
		default:
		CLEAR_BIT(UCSRC,UMSEL);
		break;
	}
	
	switch(configType_PTr->CharacterSize)
	{
		case FiveBits:
		CLEAR_BIT(UCSRC,UCSZ0);
		CLEAR_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;
		case SixBits:
		SET_BIT(UCSRC,UCSZ0);
		CLEAR_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;
		case SevenBits:
		CLEAR_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;
		case EightBits:
		SET_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;
		case NineBits:
		SET_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		SET_BIT(UCSRB,UCSZ2);
		break;
		default:
		SET_BIT(UCSRC,UCSZ0);
		SET_BIT(UCSRC,UCSZ1);
		CLEAR_BIT(UCSRB,UCSZ2);
		break;
		
		
	}
	
	switch(configType_PTr->StopBit)
	{
		case OneBit:
		CLEAR_BIT(UCSRC,USBS);
		break;
		case TwoBits:
		SET_BIT(UCSRC,USBS);
		break;
		default:
		break;
		
	}
	
	switch(configType_PTr->Parity)
	{
		case Parity_OFF:
		CLEAR_BIT(UCSRC,UPM0);
		CLEAR_BIT(UCSRC,UPM1);
		break;
		case OddParity:
		CLEAR_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1);
		break;
		case EvenParity:
		SET_BIT(UCSRC,UPM0);
		SET_BIT(UCSRC,UPM1);
		break;
		default:
		break;
	}
	switch(configType_PTr->ClockPolarity)
	{
		case Transmit_Rising_Edge_Recieve_Falling_Edge:
		CLEAR_BIT(UCSRC,UCPOL);
		break;
		case Transmit_Falling_Edge_Recieve_Rising_Edge:
		SET_BIT(UCSRC,UCPOL);
		break;
		default:
		break;
	}
	
	UART_state(configType_PTr->State);
	
	UART_interrupt(configType_PTr->Interrupt);
	
	switch(configType_PTr->Speed)
	{
		case LOWSpeed:
		BaudRate_equ=(F_CPU)/((BaudRate * 16UL)-1);
		UBRRL=BaudRate_equ;
		UBRRH=(uint8)(BaudRate_equ>>8);
		break;
		case HIGHSpeed:
		SET_BIT(UCSRA,U2X);
		BaudRate_equ=(F_CPU)/((BaudRate * 8UL)-1);
		UBRRL=BaudRate_equ; 
		UBRRH=(uint8)(BaudRate_equ>>8);
		break;
		default:
		BaudRate_equ=(F_CPU)/((BaudRate * 16UL)-1);
		UBRRL=BaudRate_equ;
		UBRRH=(uint8)(BaudRate_equ>>8);
		break;
	}
}

void UART_interrupt(uint8 interrupt )
{
	switch(interrupt)
	{
		case Interrupt_OFF:
		CLEAR_BIT(UCSRB,RXCIE);
		CLEAR_BIT(UCSRB,TXCIE);
		break;
		
		case Interrupt_ON:
		SET_BIT(UCSRB,RXCIE);
		SET_BIT(UCSRB,TXCIE);
		break;
		
		case Interrupt_RX_ON:
		SET_BIT(UCSRB,RXCIE);
		break;
		
		case Interrupt_RX_OFF:
		CLEAR_BIT(UCSRB,RXCIE);
		break;
		
		case Interrupt_TX_ON:
		SET_BIT(UCSRB,TXCIE);
		break;
		
		case  Interrupt_TX_OFF:
		CLEAR_BIT(UCSRB,TXCIE);
		break;
		
		default:
		break;
		
	}
}

void UART_state(uint8 state )
{
	switch(state)
	{
		case Transmiter:
		SET_BIT(UCSRB,TXEN);
		CLEAR_BIT(UCSRB,RXEN);
		break;
		case Reciever:
		SET_BIT(UCSRB,RXEN);
		CLEAR_BIT(UCSRB,TXEN);
		break;
		case Transmiter_Reciever:
		SET_BIT(UCSRB,RXEN);
		SET_BIT(UCSRB,TXEN);
		break;
		default:
		break;
	}
}



void UART_SendByte(uint8 data)
{
	/*wait until Date buffer is empty and ready to Write*/
	while((UCSRA&(1<<UDRE))==0);
	UDR=data;
}

void UART_SendString(uint8 * string)
{
while(*string!='\0')
	{
	UART_SendByte(*string);
	string++;
	}
	UART_SendByte('\0');
}

uint8 UART_RecieveByte(void)
{
	/*Wait until there is unread data in Date Buffer*/
	while (GET_BIT(UCSRA , RXC) ==0);
	return UDR;
}

void UART_RecieveString(uint8 * string)
{
	/*temporary variable as a buffer*/
	uint8 data;
	do 
	{
	    data=UART_RecieveByte();
		/*assign data to the string*/
		*string=data;
		/*move to next address*/
		string++;
	} while (data!='\0');
	
}