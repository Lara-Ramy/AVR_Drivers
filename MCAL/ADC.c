/*
 * ADC.c
 *
 *  Created on: Aug 4, 2023
 *      Author: larar
 */


#include "ADC.h"
#include "ADC_config.h"
#include "ADC_priv.h"
#include "../UTILS/MACROS.h"
#include "../UTILS/STD_TYPES.h"
#include "REGISTERS.h"
#include <string.h>

void (*ADC_p2f)(void) = NULL;

void ADC_vInit(void){
#if VOLT_REFERENCE == AREF
	CLR_BIT(ADMUX,6);
	CLT_BIT(ADMUX,7);
#elif VOLT_REFERENCE == AVCC
	SET_BIT(ADMUX,6);
	CLT_BIT(ADMUX,7);
#elif VOLT_REFERENCE == INTERNAL
	SET_BIT(ADMUX,6);
	SET_BIT(ADMUX,7);
#endif

#if ADJUST == RIGHT
	CLR_BIT(ADMUX,5);
#elif ADJUST == LEFT
	SET_BIT(ADMUX,5);
#endif

	Set_Prescaler();
	SET_BIT(ADCSRA,7);
}

void ADC_vChannel_Select(uint8 channel){
	ADMUX &= 0b11111000;
	channel &= 0x07;
	ADMUX |= channel;
//	SET_BIT(ADCSRA,6);
}

void ADC_vStart_Conversion(void){
	SET_BIT(ADCSRA,6);
}

uint16 ADC_u16GetReadingInt(void){
	return ADC;
}

void ADC_vInterruptEnable(void){
	SET_BIT(ADCSRA, 3);
}

uint16 ADC_u16PollingRead(void){
	uint16 adc;
	while(GET_BIT(ADCSRA, 4) == 0);
	adc = ADC;
	SET_BIT(ADCSRA,4);
	return adc;
}

static void Set_Prescaler(void){
#if ADC_PRESCALER == ADC_PRESCALER_2
	CLR_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);

#elif ADC_PRESCALER == ADC_PRESCALER_4
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);

#elif ADC_PRESCALER == ADC_PRESCALER_8
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	CLR_BIT(ADCSRA,2);

#elif ADC_PRESCALER == ADC_PRESCALER_16
	CLR_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);

#elif ADC_PRESCALER == ADC_PRESCALER_32
	SET_BIT(ADCSRA,0);
	CLR_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);

#elif ADC_PRESCALER == ADC_PRESCALER_64
	CLR_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);

#elif ADC_PRESCALER == ADC_PRESCALER_128
	SET_BIT(ADCSRA,0);
	SET_BIT(ADCSRA,1);
	SET_BIT(ADCSRA,2);
#endif
}

void ADC_SetCallBackFunction(void(*p2f)(void)){
	ADC_p2f = p2f;
}


ISR(ADC_vect){
	if(ADC_p2f!= NULL){
		ADC_p2f();
	}
}



