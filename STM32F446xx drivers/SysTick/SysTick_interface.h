#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H

#include "SysTick_private.h"
typedef enum
{
	AHB_DIVIDED_BY_8,
	AHB
}SysTick_Clock_Src;

typedef enum
{
	DISABLE_SYSTICK_EXCEPTION,
	ENABLE_SYSTICK_EXCEPTION
}SysTick_INT;


void SysTick_Init(SysTick_Clock_Src ClockSource,SysTick_INT InterruptState);
void SysTick_Start(uint32 Load_Val,uint32 Start_Val);
void SysTick_Stop(void);
void SysTick_SetCallBack(void(*pFunc)(void));

#endif /*SYSTICK_INTERFACE_H*/

