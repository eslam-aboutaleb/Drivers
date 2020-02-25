/*
 * ULTRAsonic.h
 *
 * Created: 2/20/2020 2:38:23 PM
 *  Author: Eslam Aboutaleb
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "Ultrasonic_port.h"

#define SoundSpead_CM 34000
#define SoundSpeed10us 0.034

void UltraSonic_init(void);
f32 UltraSonic_fReadDistance(void);

#endif /* ULTRASONIC_H_ */