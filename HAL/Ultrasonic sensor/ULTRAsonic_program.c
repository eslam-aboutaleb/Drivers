/*
 * ULTRAsonic.c
 *
 * Created: 2/20/2020 2:38:05 PM
 *  Author: Eslam Aboutaleb
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Ultrasonic_interface.h"

void UltraSonic_init(void)
{
	DIO_SetPinDirection(EchoPinPort,EchoPin,INPUT);
	DIO_SetPinDirection(TriggerPinPort,TriggerPin,OUTPUT);
	DIO_SetPinValue(EchoPinPort,EchoPin,STD_LOW);
	DIO_SetPinValue(TriggerPinPort,TriggerPin,STD_LOW);
	
}

f32 UltraSonic_fReadDistance(void)
{
	f32 fDistance=0;
	TMR_Counter=0;
	
	/* fire UltraSonic signal */
	DIO_SetPinValue(TriggerPinPort,TriggerPin,STD_HIGH);
	delay10us;
	DIO_SetPinValue(TriggerPinPort,TriggerPin,STD_LOW);
	
	/* wait until Echo pin receive the signal */
	while(DIO_u8GetPinValue(EchoPinPort,EchoPin)!=STD_HIGH);
	/* start the timer */
	TMR_Start();
	/* wait until Echo pin finishes receiving the signal */
	while(DIO_u8GetPinValue(EchoPinPort,EchoPin)==STD_HIGH);
	
	/* divide The time of sound travel to have
	   the distance to desired opject duration only */
	fDistance=((TMR_Counter*SoundSpeed10us)/2);
	
	TMR_Stop();
	
	return fDistance;
	
}