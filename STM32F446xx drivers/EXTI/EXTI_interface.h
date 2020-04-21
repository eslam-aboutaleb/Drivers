#ifndef EXTI_INTERFACE
#define EXTI_INTERFACE

#include "NVIC_interface.h"
#include "EXTI_private.h"

typedef enum
{
	INT_RISING_EDGE,
	INT_FALLING_EDGE,
	INT_RISING_FALLING_EDGE
}EXTI_Edge_Select;

typedef enum
{
	DISABLE_EXTI,
	ENABLE_EXTI
}EXTI_State;

typedef enum
{
	DISABLE_EXTI_EDGE,
	ENABLE_EXTI_EDGE
}EXTI_Edge_State;

void EXTI_Init(void);
void EXTI_Set_INT(uint8 Pin,IRQn_Type IRQn,EXTI_State State);
void EXTI_SetEdge(uint8 Pin,EXTI_Edge_Select Edge,EXTI_Edge_State State);
void EXTI_Clear_INT(uint8 Pin); 
void EXTI_Set_Pending_Flag(uint8 Pin);

#endif /*EXTI_INTERFACE*/

