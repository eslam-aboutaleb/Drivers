#include "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "SysTick_interface.h"
#include "OS_interface.h"

void Task1(void)
{
	DIO_SetpinVal('A',0,1);

}

void Task2(void)
{
	DIO_SetpinVal('A',1,1);

}

/*
 * void func (void)
{
	static u8 flag=0;
	if (flag==0)
	{
		DIO_SetpinVal('A',0,1);
        flag=1;
	}
	else
	{
		DIO_SetpinVal('A',0,0);
		flag=0;
	}
}

*/
void main(void)
{
	//rcc init sysclk =HSE=8MHZ
	RCC_ClockInit();
	//Enable GPIOA CLOCK
	RCC_EnableCLKprephiral(2,2);

	//Set A0 As Output Push Pull 2 MHZ
	DIO_SetPinmodde('A',0,2);
	DIO_SetPinmodde('A',1,2);

	//motor polarity pins
	DIO_SetPinmodde('A',2,2);
	DIO_SetPinmodde('A',3,2);

	//buzzer pin
	DIO_SetPinmodde('A',4,2);




	//initalize SysTick
	SystemTick_Init();

	//create task

	OS_CreateTask(0,250,Task1);
	OS_CreateTask(1,500,Task2);
    //start os
	Start_OS();

	while(1);


}
