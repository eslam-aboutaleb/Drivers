#ifndef DMA_register_H
#define DMA_register_H

#define DMA_BASE_ADDRESS 0x40020000

#define DMA_ISR    *((u32*)(DMA_BASE_ADDRESS+0x00))
#define DMA_IFCR   *((u32*)(DMA_BASE_ADDRESS+0x04))
#define DMA_CCR1   *((u32*)(DMA_BASE_ADDRESS+0x08))
#define DMA_CNDTR1 *((u32*)(DMA_BASE_ADDRESS+0x0c))
#define DMA_CPAR1  *((u32*)(DMA_BASE_ADDRESS+0x10))
#define DMA_CMAR1  *((u32*)(DMA_BASE_ADDRESS+0x14))



#endif
