#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

#include "Timer_private.h"

/*Enable clock in RCC register*/
#define RCC_TIMER1_CLK_ENABLE()         (RCC->APB2ENR |= (1<<0))
#define RCC_TIMER2_CLK_ENABLE()         (RCC->APB1ENR |= (1<<0))
#define RCC_TIMER3_CLK_ENABLE()         (RCC->APB1ENR |= (1<<1))
#define RCC_TIMER4_CLK_ENABLE()         (RCC->APB1ENR |= (1<<2))
#define RCC_TIMER5_CLK_ENABLE()         (RCC->APB1ENR |= (1<<3))
#define RCC_TIMER6_CLK_ENABLE()         (RCC->APB1ENR |= (1<<4))
#define RCC_TIMER7_CLK_ENABLE()         (RCC->APB1ENR |= (1<<5))
#define RCC_TIMER8_CLK_ENABLE()         (RCC->APB2ENR |= (1<<1))
#define RCC_TIMER9_CLK_ENABLE()         (RCC->APB2ENR |= (1<<16))
#define RCC_TIMER10_CLK_ENABLE()        (RCC->APB2ENR |= (1<<17))
#define RCC_TIMER11_CLK_ENABLE()        (RCC->APB2ENR |= (1<<18))
#define RCC_TIMER12_CLK_ENABLE()        (RCC->APB1ENR |= (1<<6))
#define RCC_TIMER13_CLK_ENABLE()        (RCC->APB1ENR |= (1<<7))
#define RCC_TIMER14_CLK_ENABLE()        (RCC->APB1ENR |= (1<<8))


typedef enum
{
	Disable_CNT,
	Enable_CNT
}CNT_State;

typedef enum
{
	Disable_TIM_Update_Interrupt,
	Enable_TIM_Update_Interrupts
}TIM_Update_INT_State;

typedef enum
{
	Disable_Update_Event,
	Enable_Update_Event
}URS_State;

typedef enum
{
	Disable_ARR_Buffer,
	Enable_ARR_Buffer
}ARR_Buffer_State;

typedef enum
{
	Edge_Aligned_Mode,
	Center_Aligned_Mode_1,
	Center_Aligned_Mode_2,
	Center_Aligned_Mode_3
}CMS_State;

typedef enum
{
	UpCounter,
	DownCounter
}DIR_State;

typedef enum
{
	Div_1,
	Div_2,
	Div_3
}Clk_Div;

typedef enum
{
	Counter_Not_stopped_Update_Event,
	Counter_stopped_Update_Event
}OPM_State;

typedef struct
{
	uint32 PeriodVal;
	uint32 PrescalerVal;
	URS_State Update_event_State;
	ARR_Buffer_State AutoReloadBuffer;
	CMS_State Center_Aligned_Mode;
	CNT_State Counter_State;
	DIR_State Direction_State;
	Clk_Div Clock_Div_Factor;
	OPM_State OnePulse_Mode;
	TIM_Update_INT_State UDI_State;
}TIM_ConfigType;

void TIM_Init(TIM_TypeDef *TIMERx,TIM_ConfigType *TIM_ConfigPtr);
void TIM_SetPeriodValue(TIM_TypeDef *TIMERx , uint32 PeriodVal);
void TIM_SetPrescalerValue(TIM_TypeDef *TIMERx , uint32 PrescalerVal);
void TIM_SetCounterState(TIM_TypeDef *TIMERx,CNT_State State);
void TIM_SetURS_State(TIM_TypeDef *TIMERx,URS_State Update_event_State);
void TIM_SetARR_Buffer(TIM_TypeDef *TIMERx,ARR_Buffer_State AutoReloadBuffer);
void TIM_SetCMS_State(TIM_TypeDef *TIMERx,CMS_State Center_Aligned_Mode);
void TIM_SetDirection(TIM_TypeDef *TIMERx,DIR_State Direction_State);
void TIM_SetClkDiv(TIM_TypeDef *TIMERx,Clk_Div Clock_Div_Factor);
void TIM_SetOPM_State(TIM_TypeDef *TIMERx,OPM_State OnePulse_Mode);
void TIM_SetUD_Interrupt(TIM_TypeDef *TIMERx,TIM_Update_INT_State State);
#endif

