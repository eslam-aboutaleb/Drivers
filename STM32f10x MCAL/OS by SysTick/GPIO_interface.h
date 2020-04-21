#ifndef GPIO_interface_H
#define GPIO_interface_H

void DIO_SetPinmodde(u8 Port , u8 pin , u8 Mode);
void DIO_SetpinVal(u8 Port , u8 Pin , u8 Value);
u8 DIO_GetpinValv  (u8 Port , u8 Pin);

#endif
