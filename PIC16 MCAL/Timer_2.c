/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Eslam Aboutaleb
File: Timer_delay.c
Date: 30/3/2020
//////////////////////////////////////////////////////////////////////////////////////////////////// */
#include "Timer_delay.h"
#include "Main.h"
/* /////////////////////////////////////////////////////////////////////////////////
Func: Delay_Init
Parameters: void
Return: void
job: Initialize timer2 in PIC MCU at prescaler 16
///////////////////////////////////////////////////////////////////////////////// */
void Delay_Init(void)
{
    TMR_DELAY_SET_PRESCALER_16;
    TMR_DELAY_DISABLE;
}
/* /////////////////////////////////////////////////////////////////////////////////
Func: Delay_Start
Parameters: void
Return: void
Job: Start Timer2
///////////////////////////////////////////////////////////////////////////////// */
void Delay_Start(void)
{
    TMR_DELAY_CLEAR_FLAG;
    TMR_DELAY_START;
}
/* /////////////////////////////////////////////////////////////////////////////////
Func: TMR_Delay_CheckOverFlow
Parameters: void
Return: tByte
job: Checks timer overflow
///////////////////////////////////////////////////////////////////////////////// */
tByte TMR_Delay_CheckOverFlow(void)
{
    return TMR_DELAY_GET_FLAG;
}
/* /////////////////////////////////////////////////////////////////////////////////
Func: Delay_Stop
Parameters: void
Return: void
job: Stops timer2
///////////////////////////////////////////////////////////////////////////////// */
void Delay_Stop(void)
{
    TMR_DELAY_DISABLE;

}
/* /////////////////////////////////////////////////////////////////////////////////
Func: TMR_Delay_MS
Parameters: void
Return: void
job: Starts the timer and generate delay in milliseconds multiplied by delay value
///////////////////////////////////////////////////////////////////////////////// */
void TMR_Delay_MS(tWord delay)
{
    tByte count=0;
    tWord index=0;
    /*Load timer register with 1 ms value*/
    TMR_DELAY_REG_VAL(131);
    for(count=0;count<delay;count++)
    {
        Delay_Start();
        /*Wait until timer overflows*/
        while(TMR_Delay_CheckOverFlow()==0);
        Delay_Stop();
        /*Reload timer register with 1 ms value*/
        TMR_DELAY_UPDATE_REG_VAL(132);
    }
}

/* /////////////////////////////////////////////////////////////////////////////////
Func: TMR_Delay_US
Parameters: void
Return: void
job: Starts the timer and generate delay in microseconds multiplied by delay value
///////////////////////////////////////////////////////////////////////////////// */
void TMR_Delay_100US(tWord delay)
{
    tByte count=0;
    tWord index=0;
    /*Load timer register with 100 us value*/
    TMR_DELAY_REG_VAL(251);
    for(count=0;count<delay;count++)
    {
        Delay_Start();
        /*Wait until timer overflows*/
        while(TMR_Delay_CheckOverFlow()==0);
        Delay_Stop();
        /*Reload timer register with 100 us value*/
        TMR_DELAY_UPDATE_REG_VAL(252);
    }
}
