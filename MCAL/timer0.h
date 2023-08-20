/*
 * timer0.h
 *
 *  Created on: Jul 28, 2023
 *      Author: larar
 */

#ifndef MCAL_TIMER0_H_
#define MCAL_TIMER0_H_



#define NORMAL_MODE 		0
#define PWM_PHASE_CORRECT 	1
#define CTC 				2
#define PWM_FAST 			3

#define NO_PRESCALER		0
#define PRESCALER_8			1
#define PRESCALER_64		2
#define PRESCALER_256		3
#define PRESCALER_1024		4

#define INVERTING			0
#define NON_INVERTING		1



void vTimer0_init(void);

void vTimer0_Check_OVF(void);

void vTimer0_Interrupt_Enable(void);

static void vSet_Prescaler(void);

void Timer0_pfSetCallback(void (*p2fvar)(void));

void Timer0_u8SetComp(uint8 comp_time);

void Timer0_vSetPWMDutyCycleFast(uint8 duty);

void Timer0_u8SetStart(uint8 start_time);

void Timer0_vStop(void);

void Timer0_vSetPWMDutyCyclePhaseCorrect(uint8 duty);






#endif /* MCAL_TIMER0_H_ */
