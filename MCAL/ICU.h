/*
 * ICU.h
 *
 *  Created on: Jul 31, 2023
 *      Author: larar
 */

#ifndef MCAL_ICU_H_
#define MCAL_ICU_H_


#define RISING_EDGE_ICU			1
#define FALLING_EDGE_ICU		2


void ICU_vInit(void);

void ICU_vGetDutyCycle(uint8 *duty);

void ICU_vGetFrequency(uint32 *frequency);

#endif /* MCAL_ICU_H_ */
