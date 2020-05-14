/* ///////////////////////////////////////////////////////////////////////////
 * 
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#ifndef FLASH_PRIVATE_H
#define FLASH_PRIVATE_H

#define FLASH_BASE_ADDRESS                0x40023C00


/* Flash sectors*/
#define FLASH_SECTOR0_BASE_ADDRESS          0x08000000
#define FLASH_SECTOR1_BASE_ADDRESS          0x08004000
#define FLASH_SECTOR2_BASE_ADDRESS          0x08008000
#define FLASH_SECTOR3_BASE_ADDRESS          0x0800C000
#define FLASH_SECTOR4_BASE_ADDRESS          0x08010000
#define FLASH_SECTOR5_BASE_ADDRESS          0x08020000
#define FLASH_SECTOR6_BASE_ADDRESS          0x08040000
#define FLASH_SECTOR7_BASE_ADDRESS          0x08060000


#define OPTION_BYTES_BASE_ADDRESS           0x1FFFC000

#define FLASH_START_ADDRESS                 0x08000000
#define FLASH_END_ADDRESS                   0x0807FFFF

typedef struct
{
  volatile uint32 ACR;      /*!< FLASH access control register,   Address offset: 0x00 */
  volatile uint32 KEYR;     /*!< FLASH key register,              Address offset: 0x04 */
  volatile uint32 OPTKEYR;  /*!< FLASH option key register,       Address offset: 0x08 */
  volatile uint32 SR;       /*!< FLASH status register,           Address offset: 0x0C */
  volatile uint32 CR;       /*!< FLASH control register,          Address offset: 0x10 */
  volatile uint32 OPTCR;    /*!< FLASH option control register ,  Address offset: 0x14 */
  volatile uint32 OPTCR1;   /*!< FLASH option control register 1, Address offset: 0x18 */
} FLASH_TypeDef;

#define Flash                           ( (FLASH_TypeDef *)  FLASH_BASE_ADDRESS)

#endif

