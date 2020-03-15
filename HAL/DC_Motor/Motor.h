#ifndef MOTOR_H_
#define MOTOR_H_

#define MOTOR_1_BI_DIRECTION

typedef enum
{
    Motor_1
}tMotor;

typedef struct
{
    tMotor_State State;
    tMotor_Directon Direction;
}tMotor_Info;

typedef enum
{
   Motor_OFF = 0,
   Motor_ON  = 1
}tMotor_State;

typedef enum
{
    Motor_ClockWise,
    Motor_AntiClockWise,
    Motor_Stopped
}tMotor_Directon;

/*Functions prototypes*/
void Motor_Init(tMotor Motor);
void Motor_SetState(tMotor Motor,tMotor_State State,tMotor_Directon Direction);
tMotor_Info Motor_GetState(tMotor Motor);
void Motor_Stop(tMotor Motor);
void Motor_Update(void);


#endif // MOTOR_H_
