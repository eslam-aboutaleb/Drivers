#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SysTick_interface.h"

static void (*SysTick_CallBack) (void);

void SysTick_Init(SysTick_Clock_Src ClockSource,SysTick_INT InterruptState)
{
	switch(ClockSource)
	{
		case AHB_DIVIDED_BY_8:
			CLEAR_BIT(SYSTICK->CTRL,2);
			break;
		case AHB:
			SET_BIT(SYSTICK->CTRL,2);
			break;
		default:
			/*No Action*/
			break;
	}
	
	switch(InterruptState)
	{
		case ENABLE_SYSTICK_EXCEPTION:
			SET_BIT(SYSTICK->CTRL,1);
			break;
		case DISABLE_SYSTICK_EXCEPTION:
			CLEAR_BIT(SYSTICK->CTRL,1);
			break;
		default:
			/*No Action*/
			break;
	}
}

void SysTick_Start(uint32 Load_Val,uint32 Start_Val)
{
	SYSTICK->LOAD=Load_Val;
	SYSTICK->VAL=Start_Val;
	SET_BIT(SYSTICK->CTRL,0);
}

void SysTick_Stop(void)
{
	CLEAR_BIT(SYSTICK->CTRL,0);
}

void SysTick_SetCallBack(void(*pFunc)(void))
{
	SysTick_CallBack=pFunc;
}


void SysTick_Handler(void)
{
	SysTick_CallBack();
}
