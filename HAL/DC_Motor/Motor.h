#ifndef MOTOR_H_
#define MOTOR_H_

#define MOTOR_1_POLARITY_PIN_POSITIVE  GPIO_PIN_0
#define MOTOR_1_POLARITY_PIN_NEGATIVE  GPIO_PIN_1
#define MOTOR_1_PORT_DR GPIO_PORTB_DATA
#define MOTOR_1_PORT_CR GPIO_PORTB_CONTROL


typedef struct
{
    tMotor_State State;
    tMotor_Directon Direction;
}tMotor_Info;

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


void Motor_Init(tMotor Motor);
void Motor_SetState(tMotor Motor,tMotor_State State,tMotor_Directon Direction);
void Motor_Stop(void);
void Motor_Update(void);


#endif // MOTOR_H_
