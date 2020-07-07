/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Eslam Aboutaleb
File: TWI.h
Date: 4/7/2020
//////////////////////////////////////////////////////////////////////////////////////////////////// */
#ifndef TWI_H_INCLUDED
#define TWI_H_INCLUDED

/*Functions prototypes*/
void I2C_Master_Init(const tWord32 baud);
void I2C_Master_Wait(void);
void I2C_Master_Start(void);
void I2C_Master_RepeatedStart(void);
void I2C_Master_Stop(void);
void I2C_ACK(void);
void I2C_NACK(void);
tByte I2C_Master_Write(tByte data);
tWord I2C_Master_Read(tWord a);

#endif // TWI_H_INCLUDED
