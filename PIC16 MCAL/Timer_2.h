/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Eslam Aboutaleb
File: Timer_delay.h
Date: 30/3/2020
//////////////////////////////////////////////////////////////////////////////////////////////////// */
#ifndef TIMER_DELAY_H
#define TIMER_DELAY_H
#include "Main.h"

void Delay_Init(void);
void Delay_Start(void);
tByte TMR_Delay_CheckOverFlow(void);
void Delay_Stop(void);
void TMR_Delay_MS(tWord delay);
void TMR_Delay_100US(tWord delay);



#endif // TIMER_DELAY_H
