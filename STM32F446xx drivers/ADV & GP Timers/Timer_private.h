#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#define TIMER1_BASE_ADDRESS                        0x40010000
#define TIMER2_BASE_ADDRESS                        0x40000000
#define TIMER3_BASE_ADDRESS                        0x40000400
#define TIMER4_BASE_ADDRESS                        0x40000800
#define TIMER5_BASE_ADDRESS                        0x40000C00
#define TIMER6_BASE_ADDRESS                        0x40001000
#define TIMER7_BASE_ADDRESS                        0x40001400
#define TIMER8_BASE_ADDRESS                        0x40010400
#define TIMER9_BASE_ADDRESS                        0x40014000
#define TIMER10_BASE_ADDRESS                       0x40014400
#define TIMER11_BASE_ADDRESS                       0x40014800
#define TIMER12_BASE_ADDRESS                       0x40001800
#define TIMER13_BASE_ADDRESS                       0x40001C00
#define TIMER14_BASE_ADDRESS                       0x40002000


typedef struct
{
  volatile uint32 CR1;         /*!< TIM control register 1,              Address offset: 0x00 */
  volatile uint32 CR2;         /*!< TIM control register 2,              Address offset: 0x04 */
  volatile uint32 SMCR;        /*!< TIM slave mode control register,     Address offset: 0x08 */
  volatile uint32 DIER;        /*!< TIM DMA/interrupt enable register,   Address offset: 0x0C */
  volatile uint32 SR;          /*!< TIM status register,                 Address offset: 0x10 */
  volatile uint32 EGR;         /*!< TIM event generation register,       Address offset: 0x14 */
  volatile uint32 CCMR1;       /*!< TIM capture/compare mode register 1, Address offset: 0x18 */
  volatile uint32 CCMR2;       /*!< TIM capture/compare mode register 2, Address offset: 0x1C */
  volatile uint32 CCER;        /*!< TIM capture/compare enable register, Address offset: 0x20 */
  volatile uint32 CNT;         /*!< TIM counter register,                Address offset: 0x24 */
  volatile uint32 PSC;         /*!< TIM prescaler,                       Address offset: 0x28 */
  volatile uint32 ARR;         /*!< TIM auto-reload register,            Address offset: 0x2C */
  volatile uint32 RCR;         /*!< TIM repetition counter register,     Address offset: 0x30 */
  volatile uint32 CCR1;        /*!< TIM capture/compare register 1,      Address offset: 0x34 */
  volatile uint32 CCR2;        /*!< TIM capture/compare register 2,      Address offset: 0x38 */
  volatile uint32 CCR3;        /*!< TIM capture/compare register 3,      Address offset: 0x3C */
  volatile uint32 CCR4;        /*!< TIM capture/compare register 4,      Address offset: 0x40 */
  volatile uint32 BDTR;        /*!< TIM break and dead-time register,    Address offset: 0x44 */
  volatile uint32 DCR;         /*!< TIM DMA control register,            Address offset: 0x48 */
  volatile uint32 DMAR;        /*!< TIM DMA address for full transfer,   Address offset: 0x4C */
  volatile uint32 OR;          /*!< TIM option register,                 Address offset: 0x50 */
} TIM_TypeDef;


#define TIMER1                   ((TIM_TypeDef*)TIMER1_BASE_ADDRESS)
#define TIMER2                   ((TIM_TypeDef*)TIMER2_BASE_ADDRESS)
#define TIMER3                   ((TIM_TypeDef*)TIMER3_BASE_ADDRESS)
#define TIMER4                   ((TIM_TypeDef*)TIMER4_BASE_ADDRESS)
#define TIMER5                   ((TIM_TypeDef*)TIMER5_BASE_ADDRESS)
#define TIMER6                   ((TIM_TypeDef*)TIMER6_BASE_ADDRESS)
#define TIMER7                   ((TIM_TypeDef*)TIMER7_BASE_ADDRESS)
#define TIMER8                   ((TIM_TypeDef*)TIMER8_BASE_ADDRESS)
#define TIMER9                   ((TIM_TypeDef*)TIMER9_BASE_ADDRESS)
#define TIMER10                  ((TIM_TypeDef*)TIMER10_BASE_ADDRESS)
#define TIMER11                  ((TIM_TypeDef*)TIMER11_BASE_ADDRESS)
#define TIMER12                  ((TIM_TypeDef*)TIMER12_BASE_ADDRESS)
#define TIMER13                  ((TIM_TypeDef*)TIMER13_BASE_ADDRESS)
#define TIMER14                  ((TIM_TypeDef*)TIMER14_BASE_ADDRESS)

#endif /*TIMER_PRIVATE_H*/

