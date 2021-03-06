#include "Main.h"
#include "Port.h"
#include "Timer.h"
#include "Motor.h"

#define MOTOR_PERIOD_MS              (10)
#define HARMONIC_PERIOD_MS           (10)
#define KURZ_DELTA                   (5)
#define MOTOR_SOFT_SWitCH_PERIOD_MS  (40)

/* ///////////////////////////////////////////////////////////////////////////////////////////////////////////
Function: Motor_Init
Parameters: Motor from type structure tMotor
return: void
function job: Initialize Motor pins & first state & direction
///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void Motor_Init(tMotor Motor)
{
    /* Initialize Motor pins*/
    switch(Motor)
    {
    case Motor_1:
        GPIO_InitPortPin(MOTOR_1_PORT_CR,MOTOR_1_POLARITY_PIN_POSITIVE,GPIO_OUT);

        #ifdef MOTOR_1_BI_DIRECTION
        GPIO_InitPortPin(MOTOR_1_PORT_CR,MOTOR_1_POLARITY_PIN_NEGATIVE,GPIO_OUT);
        #endif // MOTOR_1_BI_DIRECTION

        break;

    default:
        /* No Action*/
        break;
    }

    /*set Motor OFF*/
    Motor_SetState(Motor,Motor_OFF,Motor_Stopped);
}

/* ///////////////////////////////////////////////////////////////////////////////////////////////////////////
Function: Motor_Setstate
Parameters: Motor from type struct tMotor,State form type struct tMotor_State, Direction from type struct
tMotor_Directon
return: void
function job: Set Motor state & direction
///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void Motor_SetState(tMotor Motor,tMotor_State State,tMotor_Directon Direction)
{
    switch(Motor)
    {
   case Motor_1:
       /*Check if it is Clock wise*/
       if(Direction==Motor_ClockWise)
       {
           /*Check if state is on*/
           if(State==Motor_ON)
            {
            GPIO_WritePortPin(MOTOR_1_PORT_DR,MOTOR_1_POLARITY_PIN_POSITIVE,State);

            #ifdef MOTOR_1_BI_DIRECTION
            GPIO_WritePortPin(MOTOR_1_PORT_DR,MOTOR_1_POLARITY_PIN_NEGATIVE,0);
            #endif // MOTOR_1_BI_DIRECTION

            }
            /*Motor State is off*/
           else
            {
                Motor_Stop(Motor_1);
            }
       }

       /*Check if it is Anti Clock wise*/
       #ifdef MOTOR_1_BI_DIRECTION
       else if (Direction==Motor_AntiClockWise)
       {
        if(State==Motor_ON)
         {
        GPIO_WritePortPin(MOTOR_1_PORT_DR,MOTOR_1_POLARITY_PIN_POSITIVE,0);
        GPIO_WritePortPin(MOTOR_1_PORT_DR,MOTOR_1_POLARITY_PIN_NEGATIVE,State);
         }
         /*Motor State is off*/
        else
         {
             Motor_Stop(Motor);
         }
       }
       #endif // MOTOR_1_BI_DIRECTION

       /*Check if the Motor is n't moving any direction*/
       else if (Direction==Motor_Stopped)
       {
           /*Motor State is off*/
            Motor_Stop(Motor);
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

/* ///////////////////////////////////////////////////////////////////////////////////////////////////////////
Function: Motor_GetState
Parameters: Motor from type structure tMotor
return: struct tMotor_Info
function job: Read motor state & direction
///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
tMotor_Info * Motor_GetState(tMotor Motor)
{
    tMotor_Info *Motor_ConfigType=NULL;
    /*Initialize Motor info*/
    Motor_ConfigType->State=Motor_OFF;
    Motor_ConfigType->Direction=Motor_Stopped;

    switch(Motor)
    {
    case Motor_1:
        /*Check for Clock wise direction*/
        Motor_ConfigType->State=GPIO_ReadPortPin(MOTOR_1_PORT_CR,MOTOR_1_POLARITY_PIN_POSITIVE);
        if(Motor_ConfigType->State==Motor_ON)
            {
               Motor_ConfigType->Direction=Motor_ClockWise;
            }
         else
            {
                /* No Action*/
            }

        /*Check for Clock Anti wise direction*/
        #ifdef MOTOR_1_BI_DIRECTION
        Motor_ConfigType->State=GPIO_ReadPortPin(MOTOR_1_PORT_CR,MOTOR_1_POLARITY_PIN_NEGATIVE);
        if(Motor_ConfigType->State==Motor_ON)
            {
               Motor_ConfigType->Direction=Motor_AntiClockWise;
            }
         else
            {
                /* No Action*/
            }

         #endif // MOTOR_1_BI_DIRECTION

        /*If Motor state is off*/
        if(Motor_ConfigType->State==Motor_OFF)
           {
           /*Return the initialized states at first of function*/
           }
        else
            {
                /* No Action*/
            }

        break;

    default:
        /* No Action*/
        break;

    }
    /*End of Switch*/
            return Motor_ConfigType;

}

/* ///////////////////////////////////////////////////////////////////////////////////////////////////////////
Function: Motor_Stop
Parameters: Motor from type structure tMotor
return: void
function job: Stop Motor
///////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
void Motor_Stop(tMotor Motor)
{
    switch (Motor)
    {
      case Motor_1:

      GPIO_WritePortPin(MOTOR_1_PORT_DR,MOTOR_1_POLARITY_PIN_POSITIVE,0);

      #ifdef MOTOR_1_BI_DIRECTION
       GPIO_WritePortPin(MOTOR_1_PORT_DR,MOTOR_1_POLARITY_PIN_NEGATIVE,0);
      #endif // MOTOR_1_BI_DIRECTION
    break;


    default:
        break;
    }

}

/*specific function to VC*/
void Motor_Out(tMotor Motor)
{
    Motor_SetState(Motor,Motor_ON,Motor_ClockWise);
}

void Motor_Update(void)
{
    static tByte Motor_Harmonic_t=HARMONIC_PERIOD_MS;
    volatile static tByte Motor_Harmonic_counter=0;
    static tByte SoftSwitch_Counter=0;

    /* Check if is it time for the Motor_Update to run */
    Motor_Harmonic_counter += TMR_TICK_MS;

    if(Motor_Harmonic_counter != Motor_Harmonic_t)
    {
        return;
    }

    Motor_Harmonic_counter=0;
    Motor_Harmonic_counter += KURZ_DELTA;
    Motor_Harmonic_t       += KURZ_DELTA;

    if(Motor_Harmonic_counter>KURZ_DELTA)
    {
        Motor_Harmonic_counter=0;
        Motor_Harmonic_t=0;
    }
    else
    {
        /*NO Action*/
    }
    SoftSwitch_Counter += MOTOR_PERIOD_MS;
    if(SoftSwitch_Counter==MOTOR_SOFT_SWitCH_PERIOD_MS)
    {

    }


}
