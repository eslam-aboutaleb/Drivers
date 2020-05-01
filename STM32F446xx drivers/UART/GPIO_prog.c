#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"

void GPIO_Init(GPIO_TypeDef *GPIOx ,GPIO_ConfigType *GPIOxConfig)
{
	/*Configure GPIO pin mode*/
	GPIO_ConfgPin_Mode(GPIOx,GPIOxConfig->GPIO_PinNumber,GPIOxConfig->GPIO_PinMode);
	/*Configure Speed*/
	GPIO_ConfgPin_Speed(GPIOx,GPIOxConfig->GPIO_PinNumber,GPIOxConfig->GPIO_PinSpeed);
	/*Configure OP type*/
	GPIO_ConfgPin_OP_Type(GPIOx,GPIOxConfig->GPIO_PinNumber,GPIOxConfig->GPIO_OPType);
	/*Configure Pull mode*/
	GPIO_ConfgPin_Pull(GPIOx,GPIOxConfig->GPIO_PinNumber,GPIOxConfig->GPIO_PinPuPd);
	/*Configure Alternative function mode*/
	//GPIO_ConfgPin_AF(GPIOx,GPIOxConfig->GPIO_PinNumber,GPIOxConfig->GPIO_PinAltFuncMode);
}

/*Quick function to init port pin as high speed with no pull mode*/

void GPIO_InitPortPin(GPIO_TypeDef *GPIOx ,uint16 Pin ,uint32 Mode)
{
	GPIO_ConfigType GPIO_Pin_Conf;
	
	if(GPIOx==GPIOA)
	{
		RCC_GPIOA_CLK_ENABLE();
	}
	else if(GPIOx==GPIOB)
	{
		RCC_GPIOB_CLK_ENABLE();
	}
	else if(GPIOx==GPIOC)
	{
		RCC_GPIOC_CLK_ENABLE();
	}
	else if(GPIOx==GPIOD)
	{
		RCC_GPIOD_CLK_ENABLE();
	}
	else if(GPIOx==GPIOE)
	{
		RCC_GPIOE_CLK_ENABLE();
	}
	
	GPIO_Pin_Conf.GPIO_PinMode=Mode;
	GPIO_Pin_Conf.GPIO_OPType=GPIO_PIN_OP_PUSHPULL;
	GPIO_Pin_Conf.GPIO_PinNumber=Pin;
	GPIO_Pin_Conf.GPIO_PinPuPd=GPIO_PIN_NO_PULL_PUSH;
	GPIO_Pin_Conf.GPIO_PinSpeed=GPIO_PIN_SPEED_HIGH;
	
	GPIO_Init(GPIOx,&GPIO_Pin_Conf);
}

void GPIO_ConfgPin_Mode(GPIO_TypeDef *GPIOx ,uint16 Pin ,uint32 Mode)
{
	GPIOx->MODER |= (Mode << (2 * Pin)); /*Each pin has 2 bits in MODER register*/
}

void GPIO_ConfgPin_OP_Type(GPIO_TypeDef *GPIOx ,uint16 Pin , uint32 OP_Type)
{
	GPIOx->OTYPER |= (OP_Type << Pin); 
}

void GPIO_ConfgPin_Speed(GPIO_TypeDef *GPIOx ,uint16 Pin , uint32 Speed)
{
	GPIOx->OSPEEDR |= (Speed << (2*Pin)); /*Each pin has 2 bits in OSPEEDR register*/
}

void GPIO_ConfgPin_Pull(GPIO_TypeDef *GPIOx ,uint16 Pin , uint32 Pull_Mode)
{
	GPIOx->PUPDR |= (Pull_Mode << (2*Pin));
}

void GPIO_ConfgPin_AF(GPIO_TypeDef *GPIOx ,uint16 Pin ,uint16 AF_Mode)
{
	if(Pin<=7)
	{
		/*Low Alternative function register*/
		GPIOx->AFR[0] |= (AF_Mode << ((Pin)*4)); /*Each pin has 4 bits in AFR register*/
	}
	else
	{
		/*High Alternative function register*/
		GPIOx->AFR[1] |= (AF_Mode << ((Pin%8)*4)); /*Each pin has 4 bits in AFR register and set the modulus value
                                                 due to these are pins that are higher than 7		*/
	}
}

uint8 GPIO_ReadPortPin(GPIO_TypeDef *GPIOx ,uint16 Pin)
{
	uint8 val;
	val=((GPIOx->IDR >> Pin)&0x00000001);
	return val;
}

uint8 GPIO_WritePortPin(GPIO_TypeDef *GPIOx ,uint16 Pin ,uint8 Val)
{
	if(Val==1)
	{
		SET_BIT(GPIOx->ODR,Pin);
	}
	else
	{
		CLEAR_BIT(GPIOx->ODR,Pin);
	}
	return Val;
}



