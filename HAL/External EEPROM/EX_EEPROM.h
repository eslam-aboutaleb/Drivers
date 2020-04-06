/* ///////////////////////////////////////////////////////////////////////////
 *
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#ifndef EX_EEPROM_H_
#define EX_EEPROM_H_

#define EX_EEPROM_BASE_ADDRESS   0xA0
#define MCU_ADDRESS              0x02

void EX_EEPROM_Init(uint8 A0_State,uint8 A1_State,uint8 A2_State);
void EX_EEPROM_ReadByte(uint8 *R_Data,uint8 Section);
void EX_EEPROM_WriteByte(uint8 Data,uint8 Section);
void EX_EEPROM_ReadString(uint8 *RecvStr,uint8 Section);
void EX_EEPROM_WriteString(uint8 *SentStr,uint8 Section);
void EX_EEPROM_WriteBlocks(uint8 Section, uint8 *DataBuffer);
void EX_EEPROM_ReadBlocks(uint8 Section, uint8 *DataBuffer,uint8 N_Blocks);

#endif /* EX_EEPROM_H_ */