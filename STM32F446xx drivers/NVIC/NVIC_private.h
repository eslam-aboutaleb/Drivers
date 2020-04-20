#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

#define NVIC_BASE_ADDRESS 0xE000E100

typedef struct {
	volatile uint32 ISER[8];	/*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
	uint32 RESERVED0[24];
	volatile uint32 ICER[8];	/*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
	uint32 RSERVED1[24];
	volatile uint32 ISPR[8];	/*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
	uint32 RESERVED2[24];
	volatile uint32 ICPR[8];	/*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
	uint32 RESERVED3[24];
	volatile uint32 IABR[8];	/*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
	uint32 RESERVED4[56];
	volatile uint8 IPR[240];	/*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
	uint32 RESERVED5[644];
	volatile uint32 STIR;		/*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
} NVIC_TypeDef;


#define NVIC                ((NVIC_TypeDef*)NVIC_BASE_ADDRESS)

#endif /*NVIC_PRIVATE_H*/

