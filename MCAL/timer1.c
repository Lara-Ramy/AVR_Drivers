/*
 * timer1.c
 *
 *  Created on: Jul 31, 2023
 *      Author: larar
 */

#include "REGISTERS.h"
#include "../UTILS/STD_TYPES.h"
#include "../UTILS/MACROS.h"
#include "timer1.h"
#include "timer1_config.h"
#include "timer1_priv.h"

void Timer1_vInit(void){
#if MODE == FAST_PWM_14
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
#if PWM_MODE == NON_INVERTING
	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);
#else
	CLR_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);
#endif

#elif MODE == NORMAL
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
#elif MODE == CTC_4
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);
#elif MODE == CTC_12
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
#elif MODE == FAST_PWM_15
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);

#if PWM_MODE == NON_INVERTING
	SET_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);
#else
	CLR_BIT(TCCR1A,7);
	CLR_BIT(TCCR1A,6);
#endif
#endif

//	TCNT1 = START_TIMER;
////	ICR1 = 374;
////	OCR1A = 499;
//	vSet_Prescaler();
}

void Timer1_vStart(uint16 start_time){
	TCNT1 = start_time;
	vSet_Prescaler();
}

void Timer1_vStop(void){
	TCCR1A = 0;
	TCCR1B = 0;
}


void Timer1_vSetCompA(uint16 comp_time){
	OCR1A = comp_time;
}

void Timer1_vSetCompB(uint16 comp_time){
	OCR1B = comp_time;
}


void Timer1_SetPWMFast(uint8 duty, uint8 frequency){
#if MODE == FAST_PWM_14
#if PRESCALER == PRESCALER_64
	uint16 icr1_val = (1000000/frequency)/4 - 1;
#elif PRESCALER == PRESCALER_8
	uint16 icr1_val = (1000000/frequency)/0.5 - 1;
#elif PRESCALER == PRESCALER_256
	uint16 icr1_val = (1000000/frequency)/16 - 1;
#elif PRESCALER == PRESCALER_1024
	uint16 icr1_val = (1000000/frequency)/64 - 1;
#endif

#if PWM_MODE == NON_INVERTING
	ICR1 = icr1_val;
	OCR1A = ((icr1_val+1)*duty)/100 - 1;
#elif PWM_MODE == INVERTING
	ICR1 = icr1_val;
	OCR1A =(icr1 + 1) - ((icr1_val+1)*(duty))/100 - 1;
#endif

#elif MODE == FAST_PWM_15

#if PRESCALER == PRESCALER_64
	uint16 ocr1a_val = (1000000/frequency)/4 - 1;
#elif PRESCALER == PRESCALER_8
	uint16 ocr1a_val = (1000000/frequency)/0.5 - 1;
#elif PRESCALER == PRESCALER_256
	uint16 ocr1a_val = (1000000/frequency)/16 - 1;
#elif PRESCALER == PRESCALER_1024
	uint16 ocr1a_val = (1000000/frequency)/64 - 1;
#endif

#if PWM_MODE == NON_INVERTING
	OCR1A = ocr1a_val;
	OCR1B = ((ocr1a_val+1)*duty)/100 - 1;
#elif PWM_MODE == INVERTING
	OCR1A = ocr1a_val;
	OCR1B =(ocr1a_val + 1) - ((ocr1a_val+1)*(duty))/100 - 1;
#endif

#endif
}

static void vSet_Prescaler(void){
#if			PRESCALER == NO_PRESCALER
	SET_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
#elif 		PRESCALER == PRESCALER_8
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
#elif		PRESCALER == PRESCALER_64
	SET_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
#elif		PRESCALER == PRESCALER_256
	CLR_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
#elif		PRESCALER == PRESCALER_1024
	SET_BIT(TCCR1B,0);
	CLR_BIT(TCCR1B,1);
	SET_BIT(TCCR1B,2);
#endif
}
