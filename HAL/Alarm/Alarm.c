#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "Alarm.h"

void Alarm_Init(tAlarm Alarm, tAlarm_State state)
{
	/* Configure Alarm pins as output */
	switch (Alarm)
	{
		case ALARM_1:
		DIO_InitPin(ALARM_1_PORT_DR, ALARM_1_PIN, OUTPUT,state);
		break;
		
		default:
		/* No Thing */
		break;
	}

}

void Alarm_Toggle(tAlarm Alarm)
{
/* Toggle Alarm */
if (Alarm_GetState(Alarm) == Alarm_ON)
{
Alarm_SetState(Alarm, Alarm_OFF);
} else
{
Alarm_SetState(Alarm, Alarm_ON);
}

}

void Alarm_SetState(tAlarm Alarm, tAlarm_State state)
{
/* Set led state */
switch (Alarm)
{
case ALARM_1:
DIO_SetPinValue(ALARM_1_PORT_CR, ALARM_1_PIN, state);
break;
default:
/* No Thing */
break;
}
}

tAlarm_State Alarm_GetState(tAlarm Alarm)
{
tAlarm_State ret = Alarm_OFF;

/* Set Alarm state */
switch (Alarm)
{
case ALARM_1:
ret = DIO_ucGetPinValue(ALARM_1_PORT_CR, ALARM_1_PIN);
break;
default:
/* No Thing */
break;
}
return ret;
}

void Alarm_Update(void)
{
	
}