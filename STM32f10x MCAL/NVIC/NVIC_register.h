#ifndef NVIC_register_H
#define NVIC_register_H

#define NVIC_BASE_ADDRESS 0xE000E100
#define AIRCR_BASE_ADDRESS 0xE000ED00
#define NVIC_ISER  ((u32*)(NVIC_BASE_ADDRESS+0x00 ))
#define NVIC_ICER  ((u32*)(NVIC_BASE_ADDRESS+0x80 ))
#define NVIC_ISPR  ((u32*)(NVIC_BASE_ADDRESS+0x100))
#define NVIC_ICPR  ((u32*)(NVIC_BASE_ADDRESS+0x180))
#define AIRCR     *((u32*)(AIRCR_BASE_ADDRESS+0x0c))
#define IPR        ((u8 *)(NVIC_BASE_ADDRESS+0X300))


#endif
