#ifndef MOTOR_H_
#define MOTOR_H_

#define MOTOR_1_BI_DIRECTION


/*DC motor*/
#define MOTOR_1_POLARITY_PIN_POSITIVE  GPIO_PIN_0
#define MOTOR_1_POLARITY_PIN_NEGATIVE  GPIO_PIN_1
#define MOTOR_1_PORT_DR GPIO_PORTB_DATA
#define MOTOR_1_PORT_CR GPIO_PORTB_CONTROL

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
    Motor_ClockWise,
    Motor_AntiClockWise,
    Motor_Stopped
}tMotor_Directon;

/*Functions prototypes*/
void Motor_Init(tMotor MotorC:\Users\Dell\Documents\Vaccum Cleaner\Motor.c);
void Motor_SetState(tMotor Motor,tMotor_State State,tMotor_Directon Direction);
tMotor_Info Motor_GetState(tMotor Motor);
void Motor_Stop(tMotor Motor);
void Motor_Update(void);


#endif // MOTOR_H_
