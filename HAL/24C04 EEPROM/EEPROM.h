/* ////////////////////////////////////////////////////////////////////////////////////////////////////
Name: Eslam Aboutaleb
File: EEPROM.h
Date: 4/7/2020
//////////////////////////////////////////////////////////////////////////////////////////////////// */
#ifndef EEPROM_H_INCLUDED
#define EEPROM_H_INCLUDED


/*Functions prototypes*/
void EEPROM_Write(tWord add, tByte data);
tByte EEPROM_Read(tWord add);

#endif // EEPROM_H_INCLUDED
