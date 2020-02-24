/*
 * UART_interface.h
 *
 * Created: 2/12/2020 1:23:34 PM
 *  Author: Eslam Aboutaleb
 */ 

#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_

#include "Std_Types.h"
#include "BIT_MATH.h"
#include <avr/io.h>

#ifndef F_CPU
#define F_CPU 16000000
#endif

typedef enum
{
	Interrupt_OFF,Interrupt_ON,Interrupt_RX_ON,Interrupt_RX_OFF,Interrupt_TX_ON,Interrupt_TX_OFF
}UART_Inrterrupt;

typedef enum
{
	Asynchronous,Synchronous
}UART_Mode;

typedef enum
{
	FiveBits,SixBits,SevenBits,EightBits,NineBits
}UART_CharacterSize;

typedef enum
{
	Parity_OFF,OddParity,EvenParity
}UART_Parity;

typedef enum
{
	OneBit,TwoBits
}UART_StopBit;

typedef enum
{
	Transmit_Rising_Edge_Recieve_Falling_Edge,Transmit_Falling_Edge_Recieve_Rising_Edge
}UART_ClockPolarity;

typedef enum
{
	LOWSpeed,HIGHSpeed
}UART_TransmissionSpeed;

typedef enum
{
	Transmiter,Reciever,Transmiter_Reciever
}UART_State;

typedef enum
{
	UART_Disabled,UART_Enabled
}UART_Enable;

typedef struct
{
	UART_Mode Mode;
	uint16 BaudRate;
	UART_Inrterrupt Interrupt;
	UART_CharacterSize CharacterSize;
	UART_Parity Parity;
	UART_StopBit StopBit;
	UART_ClockPolarity ClockPolarity;
	UART_State State;
	UART_TransmissionSpeed Speed;
}UART_configType;

void UART_init(UART_configType * configType_PTr);
void UART_SendByte(uint8 data);
void UART_SendString(uint8 * string);
uint8 UART_RecieveByte(void);
void UART_RecieveString(uint8 * string);
unsigned char UART_GetChar(void);
void UART_interrupt(uint8 interrupt );
void UART_state(uint8 state );

#endif /* UART_INTERFACE_H_ */