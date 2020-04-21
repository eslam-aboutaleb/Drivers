#ifndef RCC_register_H
#define RCC_register_H

#define RCC_Base_Address 0x40021000

#define RCC_CR        *((u32*)(RCC_Base_Address+0x00))
#define RCC_CFGR      *((u32*)(RCC_Base_Address+0x04))
#define RCC_CIR       *((u32*)(RCC_Base_Address+0x08))
#define RCC_APB2STR   *((u32*)(RCC_Base_Address+0x0c))
#define RCC_APB1STR   *((u32*)(RCC_Base_Address+0x10))
#define RCC_AHBENR    *((u32*)(RCC_Base_Address+0x14))
#define RCC_APB2ENR   *((u32*)(RCC_Base_Address+0x18))
#define RCC_APB1ENR   *((u32*)(RCC_Base_Address+0x1c))
#define RCC_BDCR      *((u32*)(RCC_Base_Address+0x20))
#define RCC_CSR       *((u32*)(RCC_Base_Address+0x24))

#endif