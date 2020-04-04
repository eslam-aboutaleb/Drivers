#ifndef AFIO_register_H
#define AFIO_register_H

#define AFIO_BASE_ADDRESS 0x40010000

#define AFIO_EVCR *((u32 *)(AFIO_BASE_ADDRESS+0x00))
#define AFIO_MAPR *((u32 *)(AFIO_BASE_ADDRESS+0x04))


#endif
