/*
*      Author: Eslam
*/

#include "Std_Types.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include <avr/io.h>

void DIO_SetPortValue(uint8 ucPort, uint8 ucValue)
{
	switch(ucPort) {
		case 'A':
			PORTA = ucValue;
			break;
		case 'B':
			PORTB = ucValue;
			break;
		case 'C':
			PORTC = ucValue;
			break;
		case 'D':
			PORTD = ucValue;
			break;
	}
}

void DIO_SetPortDirection(uint8 ucPort, uint8 ucDirection){
	switch(ucPort) {
		case 'A':
			DDRA = ucDirection;
			break;
		case 'B':
			DDRB = ucDirection;
			break;
		case 'C':
			DDRC = ucDirection;
			break;
		case DIO_PORTD:
			DDRD = ucDirection;
			break;
	}
}

uint8 DIO_ucGetPortValue(uint8 ucPort) {
	uint8 ucValue;
	switch(ucPort) {
		case 'A':
			ucValue = PINA;
			break; 
		case 'B':
			ucValue = PINB;
			break;
		case 'C':
			ucValue = PINC;
			break;
		case DIO_PORTD:
			ucValue = PORTD;
			break;
	}
	return ucValue;
}

void DIO_SetPinValue(uint8 ucPort, uint8 ucPinNumber,uint8 ucValue) {
	switch(ucPort) {
		case 'A':
			if (ucValue == STD_HIGH) {
				SET_BIT(PORTA,ucPinNumber);
			}
			else {
				CLEAR_BIT(PORTA,ucPinNumber);
			}
			break;
		case 'B':
			if (ucValue == STD_HIGH) {
				SET_BIT(PORTB,ucPinNumber);
			}
			else {
				CLEAR_BIT(PORTB,ucPinNumber);
			}	
			break;
		case 'C':
			if (ucValue == STD_HIGH) {
				SET_BIT(PORTC,ucPinNumber);
			}
			else {
				CLEAR_BIT(PORTC,ucPinNumber);
			}						
			break;
		case DIO_PORTD:
			if (ucValue == STD_HIGH) {
				SET_BIT(PORTD,ucPinNumber);
			}
			else {
				CLEAR_BIT(PORTD,ucPinNumber);
			}							
			break;
	}
}

void DIO_SetPinDirection(uint8 ucPort, uint8 ucPinNumber, uint8 ucDirection) {
	switch(ucPort) {
		case 'A':
			if(ucDirection == DIO_OUTPUT) {
				SET_BIT(DDRA,ucPinNumber);
			}
			else {
				CLEAR_BIT(DDRA,ucPinNumber);
			}
			break;
		case 'B':
			if(ucDirection == DIO_OUTPUT) {
				SET_BIT(DDRB,ucPinNumber);
			}
			else {
				CLEAR_BIT(DDRB,ucPinNumber);
			}
			break;
		case 'C':
			if(ucDirection == DIO_OUTPUT) {
				SET_BIT(DDRC,ucPinNumber);
			}
			else {
				CLEAR_BIT(DDRC,ucPinNumber);
			}
			break;
		case DIO_PORTD:
			if(ucDirection == DIO_OUTPUT) {
				SET_BIT(DDRD,ucPinNumber);
			}
			else {
				CLEAR_BIT(DDRD,ucPinNumber);
			}
	}
}

uint8 DIO_ucGetPinValue(uint8 ucPort, uint8 ucPinNumber) {
	uint8 ucValue;
	switch(ucPort) {
		case 'A':
			ucValue = GET_BIT(PINA,ucPinNumber);
			break;
		case 'B':
			ucValue = GET_BIT(PINB,ucPinNumber);
			break;
		case 'C':
			ucValue = GET_BIT(PINC, ucPinNumber);
			break;
		case DIO_PORTD:
			ucValue = GET_BIT(PIND,ucPinNumber);
			break;
	}
	return ucValue;
}