/*
 * ADC.h
 *
 *  Created on: Aug 4, 2023
 *      Author: larar
 */

#ifndef MCAL_ADC_H_
#define MCAL_ADC_H_

#include "../UTILS/STD_TYPES.h"

void ADC_vInit(void);

void ADC_vChannel_Select(uint8 channel);

void ADC_vStart_Conversion(void);

uint16 ADC_u16GetReadingInt(void);

void ADC_vInterruptEnable(void);

uint16 ADC_u16PollingRead(void);

void ADC_SetCallBackFunction(void(*p2f)(void));

#endif /* MCAL_ADC_H_ */
