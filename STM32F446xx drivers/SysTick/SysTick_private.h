#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H

#define SYSTICK_BASE_ADDRESS           0xE000E010

typedef struct
{
  volatile uint32 CTRL;                   /*!< Offset: 0x000 (R/W)  SysTick Control and Status Register */
  volatile uint32 LOAD;                   /*!< Offset: 0x004 (R/W)  SysTick Reload Value Register */
  volatile uint32 VAL;                    /*!< Offset: 0x008 (R/W)  SysTick Current Value Register */
  volatile uint32 CALIB;                  /*!< Offset: 0x00C (R/ )  SysTick Calibration Register */
} SysTick_Type;

#define SYSTICK            ((SysTick_Type  *)SYSTICK_BASE_ADDRESS)

#endif /*SYSTICK_PRIVATE_H*/

