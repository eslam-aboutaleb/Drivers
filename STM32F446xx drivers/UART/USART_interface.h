#ifndef USART_INTERFACE_H
#define USART_INTERFACE_H

#include "UART_private.h"


/*Macros to enable the clocks for various UART */
#define RCC_USART1_CLK_ENABLE()           ( RCC->APB2ENR |=  ( 1 << 4))
#define RCC_USART2_CLK_ENABLE()           ( RCC->APB1ENR |=  ( 1 << 17))
#define RCC_USART3_CLK_ENABLE()           ( RCC->APB1ENR |=  ( 1 << 18))
#define RCC_UART4_CLK_ENABLE()            ( RCC->APB1ENR |=  ( 1 << 19))
#define RCC_UART5_CLK_ENABLE()            ( RCC->APB1ENR |=  ( 1 << 20))
#define RCC_USART6_CLK_ENABLE()           ( RCC->APB2ENR |=  ( 1 << 5))

/*USART alternate function macro*/
#define GPIO_AF7_USART        ((uint8)0x07)  /* USART Alternate Function mapping     */

/******************************************************************************/
/*                                                                            */
/*                                UART                                         */
/*                        Register Bit Defininitions                          */
/******************************************************************************/

/*******************  Bit definition for USART_SR register  ********************/

#define USART_REG_SR_TXE_FLAG                			( (uint32)( 1 << 7 ) )
#define USART_REG_SR_TC_FLAG                 			( (uint32)( 1 <<  6) )
#define USART_REG_SR_RXNE_FLAG               			( (uint32)( 1 << 5 ) )
#define USART_REG_SR_IDLE_FLAG               			( (uint32)( 1 << 4 ) )
#define USART_REG_SR_ORE_FLAG                			( (uint32)( 1 << 3 ) )
#define USART_REG_SR_NE_FLAG                 			( (uint32)( 1 << 2 ) )
#define USART_REG_SR_FE_FLAG                 			( (uint32)( 1 << 1 ) )
#define USART_REG_SR_PE_FLAG                 			( (uint32)( 1 << 0 ) )

/*******************  Bit definition for USART_BRR register  ********************/
#define USART_REG_BRR_MANTISSA                		( (uint32)( 1 << 4 ) ) 
#define USART_REG_BRR_FRACTION                		( (uint32)( 1 << 0 ) ) 


/*******************  Bit definition for USART_CR1 register  ********************/
#define USART_REG_CR1_OVER8               				( (uint32)( 1 << 15 ) ) 
#define USART_OVER8_ENABLE             						1
#define USART_OVER16_ENABLE           					  0

#define USART_REG_CR1_USART_EN                    ( (uint32)( 1 << 13 ) )   

#define USART_REG_CR1_UART_WL                 		( (uint32)( 1 << 12 ) ) 
#define USART_WL_1S8B            									0
#define USART_WL_1S9B              								1

#define USART_REG_CR1_TXE_INT_EN                 	( (uint32)( 1 << 7) )   
#define USART_REG_CR1_TCIE_INT_EN                	( (uint32)( 1 << 6) )   
#define USART_REG_CR1_RXNE_INT_EN                	( (uint32)( 1 << 5) )   
#define USART_REG_CR1_PEIE_INT_EN                	( (uint32)( 1 << 8) )   
#define USART_REG_CR1_TE                  			 	( (uint32)( 1 << 3) )   
#define USART_REG_CR1_RE                  			 	( (uint32)( 1 << 2) )   

/*******************  Bit definition for USART_CR2 register  ********************/
#define USART_REG_CR2_STOP_BITS                 	 12   
#define USART_STOP_BITS_1                          (uint32)0
#define USART_STOP_BITS_HALF                       (uint32)1
#define USART_STOP_BITS_2                          (uint32)2
#define USART_STOP_BITS_1NHALF                     (uint32)3


/*******************  Bit definition for USART_CR3 register  ********************/
#define USART_REG_CR3_ERR_INT_EN                  ( (uint32)( 1 << 0) )  

#define UART_STOPBITS_1        										( (uint32)0x00 )
#define UART_STOPBITS_HALF     										( (uint32)0x01 )
#define UART_STOPBITS_2        										( (uint32)0x02 )
#define UART_STOPBITS_ONENHALF 										( (uint32)0x03 )

#define UART_PARITY_NONE                  				((uint32)0x00000000)
#define UART_HWCONTROL_NONE               				((uint32)0x00000000)

#define UART_MODE_TX_RX                     			((uint32)(USART_REG_CR1_TE |USART_REG_CR1_RE))

#define UART_MODE_TX                      				((uint32)(USART_REG_CR1_TE) )

#define USART_BAUD_9600                   				(uint32)9600
#define USART_BAUD_115200                 				(uint32)115200
#define USART_BAUD_2000000                				(uint32)2000000
	


/******************************************************************************/
/*                                                                            */
/*                      Data Structures used by UART Driver                    */
/*                                                                            */
/******************************************************************************/

typedef enum
{
	USART_Interrupt_OFF,
	USART_Interrupt_ON,
	USART_Interrupt_RX_ON,
	USART_Interrupt_RX_OFF,
	USART_Interrupt_TX_ON,
	USART_Interrupt_TX_OFF,
	USART_Interrupt_PE_ON,
	USART_Interrupt_PE_OFF,
	USART_Interrupt_IDLE_ON,
	USART_Interrupt_IDLE_OFF,
	USART_Interrupt_TC_ON,
	USART_Interrupt_TC_OFF,
	USART_Interrupt_ERR_OFF,
	USART_Interrupt_ERR_ON
}USART_INT;

typedef enum
{
	USART_EightBits,
	USART_NineBits
}USART_WordLength;

typedef enum
{
	USART_Parity_OFF,
	USART_OddParity,
	USART_EvenParity
}USART_Parity;

typedef enum
{
	USART_Half_Stop_Bit,
	USART_One_Stop_Bit,
	USART_One_and_Half_Stop_Bit,
	USART_Two_Stop_Bits
}USART_StopBit;

typedef enum
{
	USART_Transmit_Rising_Edge_Recieve_Falling_Edge,
	USART_Transmit_Falling_Edge_Recieve_Rising_Edge
}USART_ClockPolarity;

typedef enum
{
	USART_LOWSpeed,
	USART_HIGHSpeed
}USART_TransmissionSpeed;

typedef enum
{
	Transmiter,
	Reciever,
	Transmiter_Reciever
}USART_TXRX;

typedef enum
{
	USART_OV8,
	USART_OV16
}USART_Sampling_State;


typedef struct
{
	uint32 BaudRate;                  /* This member configures the UART communication baud rate */
																 
	USART_WordLength WordLength;                /* Specifies the number of data bits transmitted or received in a frame */
																 
	USART_StopBit StopBits;                  /* Specifies the number of stop bits transmitted */
																
	USART_Parity Parity;                    /* Specifies the parity mode. */
											

	USART_TXRX Mode;                      /*  Specifies whether the Receive or Transmit mode is enabled or disabled */

	USART_Sampling_State OverSampling;              /*  Specifies whether the Over sampling 8 is enabled or disabled */

}USART_Init_t;



typedef struct
{
	USART_TypeDef                 *Instance;        /* UART registers base address        */

	USART_Init_t                    Init;            /* UART communication parameters      */

	uint8                       *pTxBuffPtr;      /*  Pointer to UART Tx transfer Buffer */

	uint16                      TxXferSize;       /* UART Tx Transfer size              */

	uint16                      TxXferCount;      /* UART Tx Transfer Counter           */

	uint8                       *pRxBuffPtr;      /* Pointer to UART Rx transfer Buffer */

	uint16                      RxXferSize;       /* UART Rx Transfer size              */

	uint16                     RxXferCount;      /* UART Rx Transfer Counter           */  

	uint32                 			ErrorCode;        /* UART Error code                    */
	
	
}USART_Handle;




/******************************************************************************/
/*                                                                            */
/*                           Driver APIs                                      */
/*                                                                            */
/******************************************************************************/
void UART_Init(USART_Handle *uart_handle);
void UART_SendChar(USART_Handle *USART_Handle,uint8 data);
uint8 UART_GetChar(USART_Handle *USART_Handle);


#endif /*USART_INTERFACE_H*/
