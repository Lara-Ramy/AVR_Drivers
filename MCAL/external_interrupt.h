/*
 * external_interrupt.h
 *
 *  Created on: Jul 24, 2023
 *      Author: larar
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H_
#define MCAL_EXTERNAL_INTERRUPT_H_

typedef enum{
	EXTI0, // pd2
	EXTI1,
	EXTI2
}EXTI_source;

typedef enum{
	RISING_EDGE, FALLING_EDGE, LOW_EDGE, ANY_CHANGE
}trigger_type;


void EXTI_vEnable(EXTI_source source, trigger_type trigger);
void EXTI_vDisable(EXTI_source source);

#endif /* MCAL_EXTERNAL_INTERRUPT_H_ */
