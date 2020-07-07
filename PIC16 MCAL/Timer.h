/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Eslam Aboutaleb
File: Timer.h
Date: 4/7/2020
//////////////////////////////////////////////////////////////////////////////////////////////////// */
#ifndef __TIMER_H__
#define __TIMER_H__
#include "Main.h"

#define TMR_INTERRUPT_ENABLE	    /* 0 --> Interrupts disabled */
									/* 1 --> Interrupts enabled */

#define TMR_TICK_MS				(10) /* HCF(P1, P2, ..., PN) */

/*Functions prototypes*/
void TMR_Init(void);
void TMR_Start(void);
tByte TMR_CheckOverFlow(void);
void TMR_Stop(void);
void TMR_Update(void) __interrupt 0; /* ISR @  vector 0 */

#endif
