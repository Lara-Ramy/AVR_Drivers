/*
 * timer2.h
 *
 *  Created on: Aug 2, 2023
 *      Author: larar
 */

#ifndef MCAL_TIMER2_H_
#define MCAL_TIMER2_H_


void vTimer2_init(void);

void vTimer2_Check_OVF(void);

void vTimer2_Interrupt_Enable(void);

void Timer2_u8SetComp(uint8 comp_time);

void Timer2_vSetPWMDutyCycleFast(uint8 duty);

void Timer2_u8SetStart(uint8 start_time);

void Timer2_vStop(void);

void Timer2_vSetPWMDutyCyclePhaseCorrect(uint8 duty);

void Timer2_pfSetCallback(void (*p2fvar)(void));


#endif /* MCAL_TIMER2_H_ */
