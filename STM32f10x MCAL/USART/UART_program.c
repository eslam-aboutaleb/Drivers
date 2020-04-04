#include "STD_TYPES.h"
#include  "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_register.h"

void UART_Init(void)
{
	//Enable USART1 CLK
	RCC_EnableCLKprephiral(2,14);
	//choose AFIO Port A for UART
	AFIO_Map(2,0);

	//pin 9 Alternative function OUTPUT push pull at 2 MHZ
	DIO_SetPinmodde('A',9,0b1010);

	//pin 10 floating input / GPIO mode input
	DIO_SetPinmodde('A',10,0b0100);

	//USART enabled
	SET_BIT(UART_CR1,13);
	//Word length=8 / 1 start bit// 1 stop bit by default
	SET_BIT(UART_CR1,12);
	//enable USART interrupt
	SET_BIT(UART_CR1,8);
	//enable rx,tx
	SET_BIT(UART_CR1,3);
	SET_BIT(UART_CR1,2);
	//receiver in active mode
	SET_BIT(UART_CR1,1);
	//enable TX interrupt
	SET_BIT(UART_CR1,7);
	//enable Transmission complete interrupt
	SET_BIT(UART_CR1,6);
	//enable RX interrupt
	SET_BIT(UART_CR1,5);


	//UART_CR1=0x000020EC;

	UART_BRR=0x341; //baud rate=9600
}

void UART_Disable(void)
{
	CLR_BIT(UART_CR1,13);
}


void UART_SendChar(u8 data)
{
	//check if TXE bit  //Transmit data register empty
	while(!(UART_SR & (1<<7)));
	 
	//put data in the first 8 bits of data register
	UART_DR=data;


}


u8 UART_GetChar(void){
	//check if RXNE bit until it is not empty //Read data register not empty
		while(!(UART_SR & (1<<5)));

	return ((u8)(UART_DR & 0x000000FF));
	
}

void UART_SendString(u8 *str)
{
	while(*str !=0)
	{
		UART_SendChar(*str);
		str++;
	}
	str++; //because str didn't increased the last time 
	       //because condition !=0 terminated it
	UART_SendChar('\0');
}

void UART_GetString(u8 *str)
{
	volatile u8 Tempchar=0;
	
	do
	{
		Tempchar = UART_GetChar();
		*str=Tempchar;
		str ++;
		
	}while (*str !=0); //do while to have string with terminator '\0'

}
