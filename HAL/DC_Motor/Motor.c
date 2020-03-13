#include "Main.h"
#include "Port.h"
#include "Timer.h"
#include "Motor.h"
#define MOTOR_PERIOD_MS   (20)

void Motor_Init(tMotor Motor)
{
    /* Initialize Motor pins*/
    switch(Motor)
    {
    case Motor_1:
        GPIO_InitPortPin(MOTOR_1_PORT_CR,MOTOR_1_POLARITY_PIN_POSITIVE);
        GPIO_InitPortPin(MOTOR_1_PORT_CR,MOTOR_1_POLARITY_PIN_NEGATIVE);
        break;

    default:
        /* No Action*/
        break;
    }
    /*set Motor OFF*/
    Motor_Setstate(Motor,Motor_OFF,Motor_Stopped);
}

void Motor_Setstate(tMotor Motor,tMotor_State State,tMotor_Directon Direction)
{
    switch(Motor)
    {
   case Motor_1:
       if(Direction==Motor_ClockWise)
       {
        GPIO_WritePortPin(MOTOR_1_PORT_DR,MOTOR_1_POLARITY_PIN_POSITIVE,State);
        GPIO_WritePortPin(MOTOR_1_PORT_DR,MOTOR_1_POLARITY_PIN_NEGATIVE,0);
       }
       else if (Direction==Motor_AntiClockWise)
       {
        GPIO_WritePortPin(MOTOR_1_PORT_DR,MOTOR_1_POLARITY_PIN_POSITIVE,0);
        GPIO_WritePortPin(MOTOR_1_PORT_DR,MOTOR_1_POLARITY_PIN_NEGATIVE,State);
       }
       else
       {
           /* No Action */
       }
    break;

   default:
       /* No Action */
    break;

    }
}

tMotor_Info Motor_GetState(tMotor Motor)
{
    tMotor_Info Motor_ConfigType;
    tMotor_State State_ret = Motor_OFF;

    switch(Motor)
    {
    case Motor_1:
        State_ret=GPIO_ReadPortPin(MOTOR_1_PORT_CR,MOTOR_1_POLARITY_PIN_POSITIVE);
        if(State_ret==Motor_ON)
            {
               ConfigType.State=Motor_ON;
               ConfigType.Direction=Motor_ClockWise;
               return Motor_ConfigType;
            }

        GPIO_ReadPortPin(MOTOR_1_PORT_CR,MOTOR_1_POLARITY_PIN_NEGATIVE);
        if(State_ret==Motor_ON)
            {
               ConfigType.State=Motor_ON;
               ConfigType.Direction=Motor_AntiClockWise;
               return Motor_ConfigType;
            }

        if(State_ret==Motor_OFF)
           {
               ConfigType.State=Motor_OFF;
               ConfigType.Direction=Motor_Stopped;
               return Motor_ConfigType;
           }

        break;

    default:
        /* No Action*/
        break;
    }
}

void Motor_Update(void)
{
    static tWord Motor_counter = 0;

    /* Check if it is time for the Motor_Update to run */
    Motor_counter += TMR_TICK_MS;

    if (Motor_counter != MOTOR_PERIOD_MS)
    {
        return;
    }

    Motor_counter = 0;


}
