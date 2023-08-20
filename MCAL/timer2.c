/*
 * timer2.c
 *
 *  Created on: Aug 2, 2023
 *      Author: larar
 */

#include "REGISTERS.h"
#include "timer2.h"
#include "timer2_config.h"
#include "timer2_private.h"
#include "../UTILS/MACROS.h"
#include <avr/interrupt.h>
#include "../UTILS/STD_TYPES.h"
#include <string.h>


void (*p2f_timer2)(void) = NULL;

void vTimer2_init(void){
#if			MODE == TIMER2_NORMAL_MODE
	CLR_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);

#elif 		MODE == TIMER2_PWM_PHASE_CORRECT
	SET_BIT(TCCR2,6);
	CLR_BIT(TCCR2,3);

#if PWM_MODE == TIMER2_NON_INVERTING
	CLR_BIT(TCCR2, 4);
	SET_BIT(TCCR2, 5);

#else
	SET_BIT(TCCR2, 4);
	SET_BIT(TCCR2, 5);
#endif

#elif		MODE == TIMER2_CTC
	CLR_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);
	OCR0 = COMPARE_TIMER2;

#elif		MODE == TIMER2_PWM_FAST
	SET_BIT(TCCR2,6);
	SET_BIT(TCCR2,3);

#if PWM_MODE == TIMER2_NON_INVERTING
	CLR_BIT(TCCR2, 4);
	SET_BIT(TCCR2, 5);

#else
	SET_BIT(TCCR2, 4);
	SET_BIT(TCCR2, 5);

#endif

#endif

//	vSet_Prescaler();
//	TCNT0 = START_TIMER2;
}

void vTimer2_Check_OVF(void){
	while((TIFR & 0x40) == 0);
	TCNT2 = START_TIMER2;
	TIFR |= 0x40;
}

void vTimer2_Interrupt_Enable(void){
#if MODE == TIMER2_NORMAL_MODE
	SET_BIT(TIMSK,6);
#elif MODE == TIMER2_CTC
	SET_BIT(TIMSK,7);
#endif
}

static void Set_Prescaler(void){
#if			PRESCALER == TIMER2_NO_PRESCALER
	SET_BIT(TCCR2,0);
	CLR_BIT(TCCR2,1);
	CLR_BIT(TCCR2,2);
#elif 		PRESCALER == TIMER2_PRESCALER_8
	CLR_BIT(TCCR2,0);
	SET_BIT(TCCR2,1);
	CLR_BIT(TCCR2,2);
#elif		PRESCALER == TIMER2_PRESCALER_64
	SET_BIT(TCCR2,0);
	CLR_BIT(TCCR2,1);
	CLR_BIT(TCCR2,2);
#elif		PRESCALER == TIMER2_PRESCALER_256
	CLR_BIT(TCCR2,0);
	SET_BIT(TCCR2,1);
	SET_BIT(TCCR2,2);
#elif		PRESCALER == TIMER2_PRESCALER_1024
	SET_BIT(TCCR2,0);
	SET_BIT(TCCR2,1);
	SET_BIT(TCCR2,2);
#endif
}

void Timer2_u8SetStart(uint8 start_time){
	Set_Prescaler();
	TCNT2 = start_time;
}

void Timer2_u8SetComp(uint8 comp_time){
	OCR2 = comp_time;
}

void Timer2_vStop(void){
	TCCR2 = 0x00;
}

void Timer2_vSetPWMDutyCycleFast(uint8 duty){
	if (duty <= 100) {
#if PWM_MODE == NON_INVERTING
		Timer2_u8SetComp(((duty*256)/100) - 1);

#else
		Timer2_u8SetComp(((100 - duty)*256)/100 - 1);
#endif
	}
}

void Timer2_vSetPWMDutyCyclePhaseCorrect(uint8 duty){
	if (duty <= 100) {
#if PWM_MODE == NON_INVERTING
		Timer2_u8SetComp(((duty*510)/200) - 1);

#else
		Timer2_u8SetComp(((100 - duty)*510)/200 - 1);
#endif
	}
}

void Timer2_pfSetCallback(void (*p2fvar)(void)){
	p2f_timer2 = p2fvar;
}

ISR(TIMER2_OVF_vect){
	if(p2f_timer2 != NULL){
		p2f_timer2();
	}
}

ISR(TIMER2_COMP_vect){
	if(p2f_timer2 != NULL){
		p2f_timer2();
	}
}
