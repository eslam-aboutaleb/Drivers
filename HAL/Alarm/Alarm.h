#ifndef ALARM_H_
#define ALARM_H_

#define ALARM_1_PORT_DR 'C'
#define ALARM_1_PORT_CR 'C'
#define ALARM_1_PIN      7
typedef enum
{
	ALARM_1
}tAlarm;

typedef enum
{
	Alarm_OFF = 0,
	Alarm_ON  = 1
}tAlarm_State;


void Alarm_Init(tAlarm Alarm, tAlarm_State state);
void Alarm_SetState(tAlarm Alarm, tAlarm_State state);
tAlarm_State Alarm_GetState(tAlarm Alarm);
void Alarm_Update(void);



#endif /* ALARM_H_ */