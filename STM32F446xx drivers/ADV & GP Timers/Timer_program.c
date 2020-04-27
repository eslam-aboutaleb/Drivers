#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "Timer_interface.h"


void TIM_Init(TIM_TypeDef *TIMERx,TIM_ConfigType *TIM_ConfigPtr)
{
	if(TIMERx==TIMER1)
	{
		RCC_TIMER1_CLK_ENABLE();
	}
	
	else if(TIMERx==TIMER2)
	{
		RCC_TIMER2_CLK_ENABLE();
	}
	
	else if(TIMERx==TIMER3)
	{
		RCC_TIMER3_CLK_ENABLE();
	}
	
	else if(TIMERx==TIMER4)
	{
		RCC_TIMER4_CLK_ENABLE();
	}
	
	else if(TIMERx==TIMER5)
	{
		RCC_TIMER5_CLK_ENABLE();
	}
	
	else if(TIMERx==TIMER6)
	{
		RCC_TIMER6_CLK_ENABLE();
	}
	
	else if(TIMERx==TIMER7)
	{
		RCC_TIMER7_CLK_ENABLE();
	}
	
	else if(TIMERx==TIMER8)
	{
		RCC_TIMER8_CLK_ENABLE();
	}
	
	else if(TIMERx==TIMER9)
	{
		RCC_TIMER9_CLK_ENABLE();
	}
	
	else if(TIMERx==TIMER10)
	{
		RCC_TIMER10_CLK_ENABLE();
	}
	
	else if(TIMERx==TIMER11)
	{
		RCC_TIMER11_CLK_ENABLE();
	}
	
	else if(TIMERx==TIMER12)
	{
		RCC_TIMER12_CLK_ENABLE();
	}
	
	else if(TIMERx==TIMER13)
	{
		RCC_TIMER13_CLK_ENABLE();
	}
	
	else if(TIMERx==TIMER14)
	{
		RCC_TIMER14_CLK_ENABLE();
	}
	
	TIM_SetPeriodValue(TIMERx,TIM_ConfigPtr->PeriodVal);
	
	TIM_SetPrescalerValue(TIMERx,TIM_ConfigPtr->PrescalerVal);
		
	TIM_SetURS_State(TIMERx,TIM_ConfigPtr->Update_event_State);
	
	TIM_SetARR_Buffer(TIMERx,TIM_ConfigPtr->AutoReloadBuffer);
	
	TIM_SetCMS_State(TIMERx,TIM_ConfigPtr->Center_Aligned_Mode);
	
	TIM_SetDirection(TIMERx,TIM_ConfigPtr->Direction_State);
	
	TIM_SetClkDiv(TIMERx,TIM_ConfigPtr->Clock_Div_Factor);
	
	TIM_SetOPM_State(TIMERx,TIM_ConfigPtr->OnePulse_Mode);
	
	TIM_SetUD_Interrupt(TIMERx,TIM_ConfigPtr->UDI_State);
	
	TIM_SetCounterState(TIMERx,TIM_ConfigPtr->Counter_State);

}

void TIM_SetPeriodValue(TIM_TypeDef *TIMERx , uint32 PeriodVal)
{
	TIMERx->ARR = PeriodVal;
}

void TIM_SetPrescalerValue(TIM_TypeDef *TIMERx , uint32 PrescalerVal)
{
	TIMERx->PSC = PrescalerVal;
}

void TIM_SetCounterState(TIM_TypeDef *TIMERx,CNT_State State)
{
	switch(State)
	{
		case Disable_CNT:
			CLEAR_BIT(TIMERx->CR1,0);
			break;
		case Enable_CNT:
			SET_BIT(TIMERx->CR1,0);
			break;
		default:
			break;
	}
}

void TIM_SetURS_State(TIM_TypeDef *TIMERx,URS_State Update_event_State)
{
	switch(Update_event_State)
	{
		case Disable_Update_Event:
			CLEAR_BIT(TIMERx->CR1,1);
			break;
		case Enable_Update_Event:
			SET_BIT(TIMERx->CR1,1);
			break;
		default:
			break;
	}
}

void TIM_SetARR_Buffer(TIM_TypeDef *TIMERx,ARR_Buffer_State AutoReloadBuffer)
{
	switch(AutoReloadBuffer)
	{
		case Disable_ARR_Buffer:
			CLEAR_BIT(TIMERx->CR1,7);
			break;
		case Enable_ARR_Buffer:
			SET_BIT(TIMERx->CR1,7);
			break;
		default:
			break;
	}
}

void TIM_SetCMS_State(TIM_TypeDef *TIMERx,CMS_State Center_Aligned_Mode)
{
	switch(Center_Aligned_Mode)
	{
		case Edge_Aligned_Mode:
			CLEAR_BIT(TIMERx->CR1,5);
		  CLEAR_BIT(TIMERx->CR1,6);
			break;
		
		case Center_Aligned_Mode_1:
			SET_BIT(TIMERx->CR1,5);
		  CLEAR_BIT(TIMERx->CR1,6);
			break;
		
		case Center_Aligned_Mode_2:
			CLEAR_BIT(TIMERx->CR1,5);
		  SET_BIT(TIMERx->CR1,6);
			break;
		
		case Center_Aligned_Mode_3:
			SET_BIT(TIMERx->CR1,5);
		  SET_BIT(TIMERx->CR1,6);
			break;
		
		default:
			break;
	}
}

void TIM_SetDirection(TIM_TypeDef *TIMERx,DIR_State Direction_State)
{
	switch(Direction_State)
	{
		case UpCounter:
			CLEAR_BIT(TIMERx->CR1,4);
			break;
		case DownCounter:
			SET_BIT(TIMERx->CR1,4);
			break;
		default:
			break;
	}
}

void TIM_SetClkDiv(TIM_TypeDef *TIMERx,Clk_Div Clock_Div_Factor)
{
	switch(Clock_Div_Factor)
	{
		case Div_1:
			CLEAR_BIT(TIMERx->CR1,8);
		  CLEAR_BIT(TIMERx->CR1,9);
			break;
		
		case Div_2:
			SET_BIT(TIMERx->CR1,8);
		  CLEAR_BIT(TIMERx->CR1,9);
			break;
		
		case Div_3:
			CLEAR_BIT(TIMERx->CR1,8);
		  SET_BIT(TIMERx->CR1,9);
			break;
		
		default:
			break;
	}
}

void TIM_SetOPM_State(TIM_TypeDef *TIMERx,OPM_State OnePulse_Mode)
{
	switch(OnePulse_Mode)
	{
		case Counter_Not_stopped_Update_Event:
			CLEAR_BIT(TIMERx->CR1,3);
			break;
		
		case Counter_stopped_Update_Event:
			SET_BIT(TIMERx->CR1,3);
			break;
		
		default:
			break;
	}
}

void TIM_SetUD_Interrupt(TIM_TypeDef *TIMERx,TIM_Update_INT_State State)
{
	switch(State)
	{
		case Disable_TIM_Update_Interrupt:
			CLEAR_BIT(TIMERx->DIER,0);
			break;
		case Enable_TIM_Update_Interrupts:
			SET_BIT(TIMERx->DIER,0);
			break;
		default:
			break;
	}
}