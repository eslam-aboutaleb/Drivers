#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

#define RCC_BASE_ADDRESS          0x40023800

/* Reset and Clock Control */

typedef struct
{
  volatile uint32 CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
  volatile uint32 PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  volatile uint32 CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  volatile uint32 CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  volatile uint32 AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  volatile uint32 AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  volatile uint32 AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  volatile uint32 RESERVED0;     /*!< Reserved, 0x1C                                                                    */
  volatile uint32 APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  volatile uint32 APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  volatile uint32 RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
  volatile uint32 AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  volatile uint32 AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  volatile uint32 AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  volatile uint32 RESERVED2;     /*!< Reserved, 0x3C                                                                    */
  volatile uint32 APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  volatile uint32 APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  volatile uint32 RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
  volatile uint32 AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  volatile uint32 AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  volatile uint32 AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  volatile uint32 RESERVED4;     /*!< Reserved, 0x5C                                                                    */
  volatile uint32 APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  volatile uint32 APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  volatile uint32 RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
  volatile uint32 BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  volatile uint32 CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  volatile uint32 RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
  volatile uint32 SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  volatile uint32 PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  volatile uint32 PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
  volatile uint32 DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
  volatile uint32 CKGATENR;      /*!< RCC Clocks Gated ENable Register,                            Address offset: 0x90 */
  volatile uint32 DCKCFGR2;      /*!< RCC Dedicated Clocks configuration register 2,               Address offset: 0x94 */
} RCC_TypeDef;

#define RCC ((RCC_TypeDef*) RCC_BASE_ADDRESS)

#endif

