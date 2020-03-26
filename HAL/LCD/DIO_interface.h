/*
*      Author: Eslam
*/
#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H

#ifndef F_CPU
#define F_CPU (16000000UL)
#endif

#define DIO_PORTA 'A'
#define DIO_PORTB 'B'
#define DIO_PORTC 'C'
#define DIO_PORTD 'D'

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define DIO_OUTPUT 1
#define DIO_INPUT 0

void DIO_SetPortDirection(uint8 ucPort, uint8 ucDirection);
void DIO_SetPortValue(uint8 ucPort, uint8 ucValue);
uint8 DIO_ucGetPortValue(uint8 ucPortNumberCpy);

void DIO_SetPinValue(uint8 ucPort, uint8 ucPinNumber,uint8 ucValue);
void DIO_SetPinDirection(uint8 ucPort, uint8 ucPinNumber, uint8 ucDirection);
uint8 DIO_ucGetPinValue(uint8 ucPort, uint8 ucPinNumber);
void DIO_InitPin(uint8 ucPort,uint8 ucPinNumber,uint8 ucDirection,uint8 ucState);


#endif