#ifndef MOTOR_H_
#define MOTOR_H_

#define MOTOR_1_BI_DIRECTION

typedef enum
{
    Motor_1
}tMotor;


typedef enum
{
   Motor_OFF = 0,
   Motor_ON  = 1
}tMotor_State;

typedef enum
{
    Motor_Stopped=0,
    Motor_ClockWise,
    Motor_AntiClockWise
}tMotor_Directon;



/*Motor info: State & Direction*/
typedef struct
{
    tMotor_State State;
    tMotor_Directon Direction;
}tMotor_Info;

/*Functions prototypes*/
void Motor_Init(tMotor Motor);
void Motor_SetState(tMotor Motor,tMotor_State State,tMotor_Directon Direction);
tMotor_Info * Motor_GetState(tMotor Motor);
void Motor_Stop(tMotor Motor);
void Motor_Update(void);


#endif // MOTOR_H_
