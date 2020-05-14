/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#ifndef FLASH_INTERFACE_H
#define FLASH_INTERFACE_H

#include "Flash_private.h"



/*Flash keys*/
#define FLASH_KEY_1        0x45670123
#define FLASH_KEY_2        0xCDEF89AB

#define FLASH_OPT_KEY1           0x08192A3BU
#define FLASH_OPT_KEY2           0x4C5D6E7FU


#define FLASH_TYPEERASE_SECTORS         0x00000000U  /*!< Sectors erase only          */
#define FLASH_TYPEERASE_MASSERASE       0x00000001U  /*!< Flash Mass erase activation */

#define FLASH_VOLTAGE_RANGE_1        0x00000000U  /*!< Device operating range: 1.8V to 2.1V                */
#define FLASH_VOLTAGE_RANGE_2        0x00000001U  /*!< Device operating range: 2.1V to 2.7V                */
#define FLASH_VOLTAGE_RANGE_3        0x00000002U  /*!< Device operating range: 2.7V to 3.6V                */
#define FLASH_VOLTAGE_RANGE_4        0x00000003U  /*!< Device operating range: 2.7V to 3.6V + External Vpp */


/* FLASH_Program_Parallelism FLASH Program Parallelism*/
typedef enum
{
 FLASH_PSIZE_BYTE,           
 FLASH_PSIZE_HALF_WORD,      
 FLASH_PSIZE_WORD,           
 FLASH_PSIZE_DOUBLE_WORD    
}Flash_WordSize;	
 
typedef enum
{
	Flash_Sector_0,
	Flash_Sector_1,
	Flash_Sector_2,
	Flash_Sector_3,
	Flash_Sector_4,
	Flash_Sector_5,
	Flash_Sector_6,
	Flash_Sector_7
}Flash_Sectors;

typedef enum
{
	Flash_Protect_Disable,
	Flash_Protect_Enable
}Flash_Protect_state;

typedef enum
{
	Flash_Protect_Lvl_0,
	Flash_Protect_Lvl_1,
	Flash_Protect_Lvl_2
}Flash_Protect_Lvl;



typedef struct
{
  uint32 TypeErase;   /*!< Mass erase or sector Erase.
                             This parameter can be a value of @ref FLASHEx_Type_Erase */

  uint32 Banks;       /*!< Select banks to erase when Mass erase is enabled.
                             This parameter must be a value of @ref FLASHEx_Banks */

  Flash_Sectors Sector;      /*!< Initial FLASH sector to erase when Mass erase is disabled
                             This parameter must be a value of @ref FLASHEx_Sectors */

  uint32 NbSectors;   /*!< Number of sectors to be erased.
                             This parameter must be a value between 1 and (max number of sectors - value of Initial sector)*/

  uint32 VoltageRange;/*!< The device voltage range which defines the erase parallelism
                             This parameter must be a value of @ref FLASHEx_Voltage_Range */

} FLASH_EraseInitTypeDef;

void Flash_SetWordSize(Flash_WordSize WordSize);
void Flash_UnLock(void);
void Flash_Lock(void);
uint8 Flash_Write(uint32 Address , uint16 Data);
uint32 Flash_Read(uint32 Address);
void Flash_EraseSector(uint8 SectorNum);
uint32 BigToLittle_endian(uint32 Val);
uint8 Flash_JumbAddress(uint32 Address);
uint8 Flash_VerifyAddress(uint32 Address);
uint8 Flash_GetProtectionLvl(void);
void Flash_OB_UnLcok(void);
void Flash_OB_Lcok(void);
uint8 Flash_SetProtection(Flash_Protect_state State,Flash_Protect_Lvl Level ,uint8 Sectors);

#endif

