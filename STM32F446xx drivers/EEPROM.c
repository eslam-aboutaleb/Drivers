/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Eslam Aboutaleb
File: EEPROM.c
Date: 4/7/2020
//////////////////////////////////////////////////////////////////////////////////////////////////// */
#include "Main.h"
#include "Port.h"
#include "TWI.h"
#include "EEPROM.h"

/*////////////////////////////////////////////////////////////////////////////////////// */
/*EEPROM Write byte*/
/*////////////////////////////////////////////////////////////////////////////////////// */
void EEPROM_Write(tWord add, tByte data)
{
    tByte MSB,LSB,n;
    tWord t= data;
    MSB=(add&0x01000)>>8;
    LSB=(add&0x00ff);
    n=0;
    do
    {
        /*Send start bit*/
        I2C_Master_Start();
        if(MSB)
        {
            I2C_Master_Write(0xA2);
        }
        else{
            I2C_Master_Write(0xA0);
        }
        I2C_Master_Write(LSB);
        I2C_Master_Write(t);
        I2C_Master_Stop();
        n++;
    }while((t!=EEPROM_Read(add)&&(n<10))); /*Loop until the address contains the desired value*/

}


/*////////////////////////////////////////////////////////////////////////////////////// */
/*EEPROM Write byte*/
/*////////////////////////////////////////////////////////////////////////////////////// */
tByte EEPROM_Read(tWord add)
{
    tByte MSB,LSB;
    tByte Data;
    MSB=(add&0x01000)>>8;
    LSB=(add&0x00ff);

    I2C_Master_Start();
    if(MSB)
    {
        I2C_Master_Write(0xA2);
    }
    else{
        I2C_Master_Write(0xA0);
    }
    I2C_Master_Write(LSB);
    I2C_Master_RepeatedStart();
    if(MSB)
    {
        I2C_Master_Write(0xA3);
    }
    else{
        I2C_Master_Write(0xA1);
    }
    Data=I2C_Master_Read(1);
    I2C_Master_Stop();

  return Data;
}
