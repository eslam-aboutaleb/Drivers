#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_interface.h"

void EXTI_Init(void)
{
	NVIC_Init();
}

void EXTI_Set_INT(uint8 Pin,IRQn_Type IRQn,EXTI_State State)
{
	if(State==ENABLE_EXTI)
	{
		SET_BIT(EXTI->IMR,Pin);
		NVIC_EnableInterrupt(IRQn);
	}
	else
	{
		CLEAR_BIT(EXTI->IMR,Pin);
		NVIC_DisableInterrupt(IRQn);
	}
}

void EXTI_SetEdge(uint8 Pin,EXTI_Edge_Select Edge,EXTI_Edge_State State)
{
	if(Edge==INT_RISING_EDGE)
	{
		if(State==DISABLE_EXTI_EDGE)
		{
			CLEAR_BIT(EXTI->RTSR,Pin);
		}
		else if(State==ENABLE_EXTI_EDGE)
		{
			SET_BIT(EXTI->RTSR,Pin);
		}
	}
	
	else if(Edge==INT_FALLING_EDGE)
	{
		if(State==DISABLE_EXTI_EDGE)
		{
			CLEAR_BIT(EXTI->FTSR,Pin);
		}
		else if(State==ENABLE_EXTI_EDGE)
		{
			SET_BIT(EXTI->FTSR,Pin);
		}
	}
	
	else if(Edge==INT_RISING_FALLING_EDGE)
	{
		if(State==DISABLE_EXTI_EDGE)
		{
			CLEAR_BIT(EXTI->RTSR,Pin);
			CLEAR_BIT(EXTI->FTSR,Pin);
		}
		else if(State==ENABLE_EXTI_EDGE)
		{
			SET_BIT(EXTI->RTSR,Pin);
			SET_BIT(EXTI->FTSR,Pin);
		}
	}
}


/*In ist pin bit in PR REG must be cleared after handling it otherwise the 
  Processor shall keep receiving interrupts*/
void EXTI_Clear_INT(uint8 Pin)
{
	if( GET_BIT(EXTI->PR,Pin)==1)
	{
		SET_BIT(EXTI->PR,Pin);
	}
	else
	{
		/*Do Nothing*/
	}
}

void EXTI_Set_Pending_Flag(uint8 Pin)
{
	SET_BIT(EXTI->SWIER,Pin);
}


