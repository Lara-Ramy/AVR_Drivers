/*
 * ADC_priv.h
 *
 *  Created on: Aug 4, 2023
 *      Author: larar
 */

#ifndef MCAL_ADC_PRIV_H_
#define MCAL_ADC_PRIV_H_

#define AREF				1
#define AVCC				2
#define INTERNAL			3

#define LEFT_ADJUST			1
#define RIGHT_ADJUST		2

#define ADC_PRESCALER_2		1
#define ADC_PRESCALER_4		2
#define ADC_PRESCALER_8		3
#define ADC_PRESCALER_16	4
#define ADC_PRESCALER_32	5
#define ADC_PRESCALER_64	6
#define ADC_PRESCALER_128	7


static void Set_Prescaler(void);

#endif /* MCAL_ADC_PRIV_H_ */
