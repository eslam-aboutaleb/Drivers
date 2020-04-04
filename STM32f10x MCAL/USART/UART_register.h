#ifndef UART_regestir_H
#define UART_regestir_H

#define UART_BASE_ADDRESS 0x40013800

#define UART_SR   *((u32*) (UART_BASE_ADDRESS+0x00))
#define UART_DR   *((u32*) (UART_BASE_ADDRESS+0x04))
#define UART_BRR  *((u32*) (UART_BASE_ADDRESS+0x08))
#define UART_CR1  *((u32*) (UART_BASE_ADDRESS+0x0C))
#define UART_CR2  *((u32*) (UART_BASE_ADDRESS+0x10))
#define UART_CR3  *((u32*) (UART_BASE_ADDRESS+0x14))
#define UART_GTPR *((u32*) (UART_BASE_ADDRESS+0x18))



#endif
