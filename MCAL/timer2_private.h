/*
 * timer2_private.h
 *
 *  Created on: Aug 3, 2023
 *      Author: larar
 */

#ifndef MCAL_TIMER2_PRIVATE_H_
#define MCAL_TIMER2_PRIVATE_H_

#define TIMER2_NORMAL_MODE 			1
#define TIMER2_PWM_PHASE_CORRECT 	2
#define TIMER2_CTC 					3
#define TIMER2_PWM_FAST 			4

#define TIMER2_NO_PRESCALER			1
#define TIMER2_PRESCALER_8			2
#define TIMER2_PRESCALER_64			3
#define TIMER2_PRESCALER_256		4
#define TIMER2_PRESCALER_1024		5

#define TIMER2_INVERTING			1
#define TIMER2_NON_INVERTING		2


static void Set_Prescaler(void);

#endif /* MCAL_TIMER2_PRIVATE_H_ */
