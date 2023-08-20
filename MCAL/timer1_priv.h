/*
 * timer1_priv.h
 *
 *  Created on: Aug 5, 2023
 *      Author: larar
 */

#ifndef MCAL_TIMER1_PRIV_H_
#define MCAL_TIMER1_PRIV_H_

#define NO_PRESCALER		1
#define PRESCALER_8			2
#define PRESCALER_64		3
#define PRESCALER_256		4
#define PRESCALER_1024		5

#define NORMAL				0
#define CTC_4				4
#define CTC_12				12
#define FAST_PWM_14			14
#define FAST_PWM_15			15

#define INVERTING			1
#define NON_INVERTING		2

static void vSet_Prescaler(void);

#endif /* MCAL_TIMER1_PRIV_H_ */
