#ifndef USART_PRIVATE_H
#define USART_PRIVATE_H

#define USART1_BASE_ADDRESS        0x40011000
#define USART2_BASE_ADDRESS        0x40004400
#define USART3_BASE_ADDRESS        0x40004800
#define UART4_BASE_ADDRESS         0x40004C00
#define UART5_BASE_ADDRESS         0x40005000
#define USART6_BASE_ADDRESS        0x40011400


typedef struct
{
	uint32 SR;
	uint32 DR;
	uint32 BRR;
	uint32 CR1;
	uint32 CR2;
	uint32 CR3;
	uint32 GTPR;
}USART_TypeDef;


#define USART1                 ((USART_TypeDef     *)USART1_BASE_ADDRESS)
#define USART2                 ((USART_TypeDef     *)USART2_BASE_ADDRESS)
#define USART3                 ((USART_TypeDef     *)USART3_BASE_ADDRESS)
#define UART4                  ((USART_TypeDef     *)UART4_BASE_ADDRESS )
#define UART5                  ((USART_TypeDef     *)UART5_BASE_ADDRESS )
#define USART6                 ((USART_TypeDef     *)USART6_BASE_ADDRESS)



#endif /*USART_PRIVATE_H*/

