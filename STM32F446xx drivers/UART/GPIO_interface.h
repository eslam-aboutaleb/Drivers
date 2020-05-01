#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "GPIO_private.h"

/*GPIO Mode settings values*/
#define GPIO_PIN_INPUT_MODE                  ((uint32)0x00)
#define GPIO_PIN_OUTPUT_MODE                 ((uint32)0x01)
#define GPIO_PIN_ALT_FUN_MODE                ((uint32)0x02)
#define GPIO_PIN_ANALOG_MODE                 ((uint32)0x03)

/*GPIO OP type selection values*/
#define GPIO_PIN_OP_PUSHPULL                 ((uint32)0x00)
#define GPIO_PIN_OP_OPENDRAIN                ((uint32)0x01)

/*GPIO Speed type selection values*/
#define GPIO_PIN_SPEED_LOW                   ((uint32)0x00)
#define GPIO_PIN_SPEED_MEDIUM                ((uint32)0x01)
#define GPIO_PIN_SPEED_HIGH                  ((uint32)0x02)
#define GPIO_PIN_SPEED_VERY_HIGH             ((uint32)0x03)

/*GPIO Pullup/pulldown selection values*/
#define GPIO_PIN_NO_PULL_PUSH                ((uint32)0x00)
#define GPIO_PIN_PULL_UP                     ((uint32)0x01)
#define GPIO_PIN_PULL_DOWN                   ((uint32)0x11)

/*Enable clock in RCC register*/
#define RCC_GPIOA_CLK_ENABLE()        (RCC->AHB1ENR |= (1<<0))
#define RCC_GPIOB_CLK_ENABLE()        (RCC->AHB1ENR |= (1<<1))
#define RCC_GPIOC_CLK_ENABLE()        (RCC->AHB1ENR |= (1<<2))
#define RCC_GPIOD_CLK_ENABLE()        (RCC->AHB1ENR |= (1<<3))
#define RCC_GPIOE_CLK_ENABLE()        (RCC->AHB1ENR |= (1<<4))

/*GPIO Pins*/

#define GPIO_PIN_0                  (0)
#define GPIO_PIN_1                  (1)
#define GPIO_PIN_2                  (2)
#define GPIO_PIN_3                  (3)
#define GPIO_PIN_4                  (4)
#define GPIO_PIN_5                  (5)
#define GPIO_PIN_6                  (6)
#define GPIO_PIN_7                  (7)
#define GPIO_PIN_8                  (8)
#define GPIO_PIN_9                  (9)
#define GPIO_PIN_10                 (10)
#define GPIO_PIN_11                 (11)
#define GPIO_PIN_12                 (12)
#define GPIO_PIN_13                 (13)
#define GPIO_PIN_14                 (14)
#define GPIO_PIN_15                 (15)
				

/*GPIO Level values*/
#define GPIO_OUT                    (1)
#define GPIO_IN                     (0)
/* Data structure of initialization function */
typedef struct
{
	uint16 GPIO_PinNumber;
	uint32 GPIO_PinMode;		
	uint32 GPIO_PinSpeed;			
	uint32 GPIO_PinPuPd;	
	uint32 GPIO_OPType;			
	uint32 GPIO_PinAltFuncMode;
}GPIO_ConfigType;


/*Functions prototype*/
void GPIO_Init(GPIO_TypeDef *GPIOx ,GPIO_ConfigType *GPIOxConfig);
void GPIO_ConfgPin_Mode(GPIO_TypeDef *GPIOx ,uint16 Pin ,uint32 Mode);
void GPIO_ConfgPin_OP_Type(GPIO_TypeDef *GPIOx ,uint16 Pin , uint32 OP_Type);
void GPIO_ConfgPin_Speed(GPIO_TypeDef *GPIOx ,uint16 Pin , uint32 Speed);
void GPIO_ConfgPin_Pull(GPIO_TypeDef *GPIOx ,uint16 Pin , uint32 Pull_Mode);
void GPIO_ConfgPin_AF(GPIO_TypeDef *GPIOx ,uint16 Pin ,uint16 AF_Mode);
uint8 GPIO_ReadPortPin(GPIO_TypeDef *GPIOx ,uint16 Pin);
uint8 GPIO_WritePortPin(GPIO_TypeDef *GPIOx ,uint16 Pin ,uint8 Val);
void GPIO_InitPortPin(GPIO_TypeDef *GPIOx ,uint16 Pin ,uint32 Mode);

#endif

