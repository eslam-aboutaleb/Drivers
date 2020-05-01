#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "USART_interface.h"


void USART_Enable(USART_TypeDef *USARTx)
{
	
	USARTx->CR1 |= USART_REG_CR1_USART_EN;
}


void USART_Disable(USART_TypeDef *USARTx)
{
	USARTx->CR1 &= ~USART_REG_CR1_USART_EN;
}


void USART_Set_TX_RX(USART_TypeDef *USARTx,USART_TXRX State)
{
	/*Clear TX & RX bits*/
	USARTx->CR1 &= ~USART_REG_CR1_RE;
	USARTx->CR1 &= ~USART_REG_CR1_TE;
	switch(State)
	{
		case Transmiter:
		USARTx->CR1 |= USART_REG_CR1_TE;
			break;
		
		case Reciever:
		USARTx->CR1 |= USART_REG_CR1_RE;	
			break;
		
		case Transmiter_Reciever:
		USARTx->CR1 |= USART_REG_CR1_RE;
		USARTx->CR1 |= USART_REG_CR1_TE;
			break;
		
		default:
			/*No Action*/
			break;
	}
}

void USART_Config_Word_Length(USART_TypeDef *uartx, USART_WordLength Length)
{
	if(Length == USART_NineBits)
	{
		uartx->CR1 |= USART_REG_CR1_UART_WL;//9data bits
	}
	else
	{
		uartx->CR1 &= ~USART_REG_CR1_UART_WL;//8 data bits 
	}
	
}


void USART_Config_StopBits(USART_TypeDef *UARTx, USART_StopBit Nstop)
{
	/*clear the 12th and 13 th bits */
	UARTx->CR2 &= ~( 0x3 << USART_REG_CR2_STOP_BITS);
	
	if(Nstop == USART_Half_Stop_Bit)
	{
		UARTx->CR2 |= ( 0x01<< USART_REG_CR2_STOP_BITS);//0.5 stop bits
	
	}
	else if(Nstop == USART_Two_Stop_Bits)
	{
		UARTx->CR2 |= ( 0x02<< USART_REG_CR2_STOP_BITS);//2 stop bits 
	
	}
	else if (Nstop == USART_One_and_Half_Stop_Bit)
	{
		UARTx->CR2 |= ( 0x03<< USART_REG_CR2_STOP_BITS);//1.5 stop bits
	
	}
	else
	{
		UARTx->CR2 |= ( 0x00<< USART_REG_CR2_STOP_BITS);// 1 stop bits
	}
	
}

void USART_Config_OverSampling(USART_TypeDef *UARTx, USART_Sampling_State over8)
{
	if(over8==USART_OV8)
	{
		UARTx->CR1 |= USART_REG_CR1_OVER8;
	}
	else
	{
		UARTx->CR1 &= ~USART_REG_CR1_OVER8;
	}
}	
	
void USART_Set_BaudRate(USART_TypeDef *UARTx, uint32 Baud)
{
	uint32 val;
	if (Baud == USART_BAUD_9600)
	{
		val = 0x683;
	}
	else if (Baud == USART_BAUD_115200)
	{
		val = 0x8A;
		
	}
	else
	{
		val = 0x8A;
	}
	UARTx->BRR = val;
}


void USART_Config_TXE_Interrupt(USART_TypeDef *USARTx, uint8 TXE_EN)
{
	if(TXE_EN)
		USARTx->CR1 |= USART_REG_CR1_TXE_INT_EN;
	else
		USARTx->CR1 &= ~USART_REG_CR1_TXE_INT_EN;
}


void USART_Config_RXNE_Interrupt(USART_TypeDef *USARTx, uint8 RXNE_EN)
{
	if(RXNE_EN)
		USARTx->CR1 |= USART_REG_CR1_RXNE_INT_EN;
	else
		USARTx->CR1 &= ~USART_REG_CR1_RXNE_INT_EN;
}


void USART_Config_ERR_Interrupt(USART_TypeDef *USARTx, uint8 ERR_EN)
{
	if(ERR_EN)
		USARTx->CR3 |= USART_REG_CR3_ERR_INT_EN;
	else
		USARTx->CR3 &= ~USART_REG_CR3_ERR_INT_EN;
}


void USART_Config_Parity_ERR_Interrupt(USART_TypeDef *USARTx, uint8 PE_EN)
{
	if(PE_EN)
		USARTx->CR1 |= USART_REG_CR1_PEIE_INT_EN;
	else
		USARTx->CR1 &= ~USART_REG_CR1_PEIE_INT_EN;
}

static void USART_RCC(USART_TypeDef *USARTx)
{
	if(USARTx == USART1)
	{
		RCC_USART1_CLK_ENABLE();
	}
	
	else if(USARTx == USART2)
	{
		RCC_USART2_CLK_ENABLE();
	}
	
	else if(USARTx == USART3)
	{
		RCC_USART3_CLK_ENABLE();
	}
	
	else if(USARTx == UART4)
	{
		RCC_UART4_CLK_ENABLE();
	}
	
	else if(USARTx == UART5)
	{
		RCC_UART5_CLK_ENABLE();
	}
	
	else if(USARTx == USART6)
	{
		RCC_USART6_CLK_ENABLE();
	}
	
	else
	{
		/*No Action*/
	}
}	


static void USART_SetPins(USART_TypeDef *USARTx)
{
	GPIO_ConfigType UART_GPIO;
	
	UART_GPIO.GPIO_PinMode=GPIO_PIN_ALT_FUN_MODE;
	UART_GPIO.GPIO_PinPuPd=GPIO_PIN_NO_PULL_PUSH;
	UART_GPIO.GPIO_PinSpeed=GPIO_PIN_SPEED_HIGH;
	UART_GPIO.GPIO_OPType=GPIO_PIN_OP_PUSHPULL;

	if(USARTx == USART1)
	{
		RCC_GPIOA_CLK_ENABLE();
		
		UART_GPIO.GPIO_PinNumber=GPIO_PIN_9;
		GPIO_ConfgPin_AF(GPIOA,GPIO_PIN_9,GPIO_AF7_USART);
		GPIO_Init(GPIOA,&UART_GPIO);
		
		UART_GPIO.GPIO_PinNumber=GPIO_PIN_10;
		GPIO_ConfgPin_AF(GPIOA,GPIO_PIN_10,GPIO_AF7_USART);
		GPIO_Init(GPIOA,&UART_GPIO);
		
	}
	
	else if(USARTx == USART2)
	{
		RCC_GPIOA_CLK_ENABLE();
		
		UART_GPIO.GPIO_PinNumber=GPIO_PIN_2;
		GPIO_ConfgPin_AF(GPIOA,GPIO_PIN_2,GPIO_AF7_USART);
		GPIO_Init(GPIOA,&UART_GPIO);
		
		UART_GPIO.GPIO_PinNumber=GPIO_PIN_3;
		GPIO_ConfgPin_AF(GPIOA,GPIO_PIN_3,GPIO_AF7_USART);
		GPIO_Init(GPIOA,&UART_GPIO);
		
	}
	
	else if(USARTx == USART3)
	{
		RCC_GPIOB_CLK_ENABLE();
		RCC_GPIOC_CLK_ENABLE();
		
		UART_GPIO.GPIO_PinNumber=GPIO_PIN_10;
		GPIO_ConfgPin_AF(GPIOB,GPIO_PIN_10,GPIO_AF7_USART);
		GPIO_Init(GPIOB,&UART_GPIO);
		
		UART_GPIO.GPIO_PinNumber=GPIO_PIN_5;
		GPIO_ConfgPin_AF(GPIOC,GPIO_PIN_5,GPIO_AF7_USART);
		GPIO_Init(GPIOC,&UART_GPIO);
	}
	
	else if(USARTx == UART4)
	{
		RCC_GPIOA_CLK_ENABLE();
		
		UART_GPIO.GPIO_PinNumber=GPIO_PIN_0;
		GPIO_ConfgPin_AF(GPIOA,GPIO_PIN_0,GPIO_AF7_USART);
		GPIO_Init(GPIOA,&UART_GPIO);
		
		UART_GPIO.GPIO_PinNumber=GPIO_PIN_1;
		GPIO_ConfgPin_AF(GPIOA,GPIO_PIN_1,GPIO_AF7_USART);
		GPIO_Init(GPIOA,&UART_GPIO);
	  
	}
	
	else if(USARTx == UART5)
	{
		RCC_GPIOC_CLK_ENABLE();
		RCC_GPIOD_CLK_ENABLE();
		
		UART_GPIO.GPIO_PinNumber=GPIO_PIN_12;
		GPIO_ConfgPin_AF(GPIOC,GPIO_PIN_12,GPIO_AF7_USART);
		GPIO_Init(GPIOC,&UART_GPIO);
		
		UART_GPIO.GPIO_PinNumber=GPIO_PIN_2;
		GPIO_ConfgPin_AF(GPIOD,GPIO_PIN_2,GPIO_AF7_USART);
		GPIO_Init(GPIOD,&UART_GPIO);
	}
	
	else if(USARTx == USART6)
	{
		RCC_GPIOC_CLK_ENABLE();
		
		UART_GPIO.GPIO_PinNumber=GPIO_PIN_6;
		GPIO_ConfgPin_AF(GPIOC,GPIO_PIN_6,GPIO_AF7_USART);
		GPIO_Init(GPIOC,&UART_GPIO);
		
		UART_GPIO.GPIO_PinNumber=GPIO_PIN_7;
		GPIO_ConfgPin_AF(GPIOC,GPIO_PIN_7,GPIO_AF7_USART);
		GPIO_Init(GPIOC,&UART_GPIO);
	}
	
	else
	{
		/*No Action*/
	}
}



void UART_Init(USART_Handle *uart_handle)
{
	/*Enable UART pins*/
	USART_SetPins(uart_handle->Instance);
	/*Enable Clock for USART*/
	USART_RCC(uart_handle->Instance);
	/* Configure the Word length */
	USART_Config_Word_Length(uart_handle->Instance,uart_handle->Init.WordLength);
	
	/*Configure the number of STOP bits */
	USART_Config_StopBits(uart_handle->Instance,uart_handle->Init.StopBits);
	
	/*Configure the oversampling rate for the receive block */	
	USART_Config_OverSampling(uart_handle->Instance,uart_handle->Init.OverSampling);
	
	/*Set the baud rate */
	USART_Set_BaudRate(uart_handle->Instance,uart_handle->Init.BaudRate);

	/*Enable the Transmit block of the UART peripheral */
	/*Enable the Receive block of the UART Peripheral */
	USART_Set_TX_RX(uart_handle->Instance,uart_handle->Init.Mode);
		
  /* Enable the UART peripheral */
	USART_Enable(uart_handle->Instance);	
	
}


void UART_SendChar(USART_Handle *USART_Handle,uint8 data)
{ 
	
	/*Put data in the first 8 bits of data register*/
	USART_Handle->Instance->DR=data;
	
	/*Check if TXE bit, Transmit data register empty*/
	while(GET_BIT((USART_Handle->Instance->SR),7)==0);
	
}

uint8 UART_GetChar(USART_Handle *USART_Handle)
{
	/*Check if RXNE bit until it is not empty, Read data register not empty*/
		while(GET_BIT(USART_Handle->Instance->SR,5)==0);

	return ((uint8)(USART_Handle->Instance->DR & 0x000001FF));
}

