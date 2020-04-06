/* ///////////////////////////////////////////////////////////////////////////
 *
 *
 *  Author: Eslam Aboutaleb
/////////////////////////////////////////////////////////////////////////// */ 

#ifndef TWI_PRIVATE_H_
#define TWI_PRIVATE_H_

#include "avr/io.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#define TWI_NORMAL_MODE 100000UL
#define TWI_FAST_MODE   400000UL

/*TWI master status*/
#define TWI_START         0x08         /* start has been sent                                                                     */
#define TWI_REP_START     0x10         /* repeated start																		  */
#define TWI_MT_SLA_W_ACK  0x18         /* Master transmit ( slave address + Write request ) to slave + Ack received from slave    */
#define TWI_MT_SLA_R_ACK  0x40         /* Master transmit ( slave address + Read request ) to slave + Ack received from slave     */
#define TWI_MT_DATA_NACK  0x20         /* Master transmit data and NACK has been received from Slave.							  */
#define TWI_MT_DATA_ACK   0x28         /* Master transmit data and ACK has been received from Slave.							  */
#define TWI_MR_DATA_ACK   0x50         /* Master received data and send ACK to slave											  */
#define TWI_MR_DATA_NACK  0x58         /* Master received data but doesn't send ACK to slave									  */
#define TWI_SLV_DATA_ACK  0x80         /* */





#endif /* TWI_PRIVATE_H_ */