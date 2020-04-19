#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS       0x40020000
#define GPIOB_BASE_ADDRESS       0x40020400
#define GPIOC_BASE_ADDRESS       0x40020800
#define GPIOD_BASE_ADDRESS       0x40020C00
#define GPIOE_BASE_ADDRESS       0x40021000


/* brief General Purpose I/O */
typedef struct
{
  volatile uint32 MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  volatile uint32 OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  volatile uint32 OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  volatile uint32 PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  volatile uint32 IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  volatile uint32 ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  volatile uint32 BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  volatile uint32 LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  volatile uint32 AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;


#define GPIOA                 ((GPIO_TypeDef   *) GPIOA_BASE_ADDRESS   )
#define GPIOB                 ((GPIO_TypeDef   *) GPIOB_BASE_ADDRESS   )
#define GPIOC                 ((GPIO_TypeDef   *) GPIOC_BASE_ADDRESS   )
#define GPIOD                 ((GPIO_TypeDef   *) GPIOD_BASE_ADDRESS   )
#define GPIOE                 ((GPIO_TypeDef   *) GPIOE_BASE_ADDRESS   )

#define GPIO_PORTA                 (GPIOA->ODR)
#define GPIO_PINA                  (GPIOA->IDR)
				
#define GPIO_PORTB                 (GPIOB->ODR)
#define GPIO_PINB                  (GPIOB->IDR)
				
#define GPIO_PORTC                 (GPIOC->ODR)
#define GPIO_PINC                  (GPIOC->IDR)
				
#define GPIO_PORTD                 (GPIOD->ODR)
#define GPIO_PIND                  (GPIOD->IDR)

#define GPIO_PORTE                 (GPIOE->ODR)
#define GPIO_PINE                  (GPIOE->IDR)
 
 
#endif