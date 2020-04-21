#include "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "SysTick_interface.h"
#include "SysTick_register.h"


void (*SystemTick_CallBack)(void);

void SystemTick_Init(void)
{
	//enable interrupt -clock source =AHB/8
	SystemTick_CTRL=0x00000002;
}

void SystemTick_Start(u32 Value)
{
	SystemTick_LOAD=Value; //make load equal to value
	SystemTick_VALUE=0; //clear value
	SET_BIT(SystemTick_CTRL,0); //make bit 0 high to enable timer
}

void SystemTick_SetCallBack(void(*ptr)(void))
{

SystemTick_CallBack=ptr;
}

void SysTick_Handler(void)
{
	SystemTick_CallBack();
}
