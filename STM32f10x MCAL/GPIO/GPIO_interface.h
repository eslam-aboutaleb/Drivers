#ifndef GPIO_interface_H
#define GPIO_interface_H

void DIO_SetPinMode(u8 Port , u8 pin , u8 Mode);
void DIO_SetPinVal(u8 Port , u8 Pin , u8 Value);
u8 DIO_GetPinVal  (u8 Port , u8 Pin);

#endif
