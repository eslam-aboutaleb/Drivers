#ifndef UART_interface_H
#define UART_interface_H

void UART_Init(void);
void UART_Disable(void);
void UART_SendChar(u8 data);
u8 UART_GetChar(void);
void UART_SendString(u8 *str);
void UART_GetString(u8 *str);

#endif
