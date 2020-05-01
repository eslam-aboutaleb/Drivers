#ifndef RCC_INTERFACE
#define RCC_INTERFACE

#include "RCC_private.h"

typedef enum
{
	HSI,
	HSE,
	PLL
}RCC_ClockSrc;

typedef enum
{
	RCC_AHB,
	RCC_APB1,
	RCC_APB2
}RCC_BUS;

typedef enum
{
	Disable_Prephiral,
	Enable_Prephiral
}RCC_PeripheralState;

typedef enum
{
	/*RCC AHB1 Peripherals*/
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG,
	GPIOH,
	CRC  =12,
	DMA1 =21,
	DMA2 =22,
	
	/*RCC APB1ENR Peripherals*/
	TIM2=0,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	TIM12,
	TIM13,
	TIM14,
	WWDG=11,
	SPI2=14,
	SPI3,
	SPDIFRX,
	USART2,
	USART3,
	USART4,
	USART5,
	I2C1,
	I2C2,
	I2C3,
	FMPI2C1,
	CAN1,
	CAN2,
	CEC,
	PWR,
	DAC,
	
	/*RCC APB2ENR Peripherals*/
 	TIM1 =0,
	TIM8,
	USART1=4,
	USART6,
	ADC1=8,
	ADC2,
	ADC3,
	SDIO,
	SPI1,
	SPI4,
	SYSCNFG,
	TIM9=16,
	TIM10,
	TIM11,
	SAI1=22,
	SAI2
	
}RCC_Peripheral;



/*Functions*/
void RCC_ClockInit(RCC_ClockSrc Clock);
void RCC_SetCLKprephiral(RCC_BUS Bus,RCC_Peripheral Prephiral,RCC_PeripheralState State);

#endif

