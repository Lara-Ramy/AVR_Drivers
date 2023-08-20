/*
 * timer0.c
 *
 *  Created on: Jul 28, 2023
 *      Author: larar
 */
#include "REGISTERS.h"
#include "timer0.h"
#include "timer0_config.h"
#include "../UTILS/MACROS.h"
#include <avr/interrupt.h>
#include "../UTILS/STD_TYPES.h"
#include <string.h>

void (*p2f)(void) = NULL;

void vTimer0_init(void){
#if			MODE == NORMAL_MODE
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

#elif 		MODE == PWM_PHASE_CORRECT
	SET_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);

#if PWM_MODE == NON_INVERTING
	CLR_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);

#else
	SET_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);
#endif

#elif		MODE == CTC
	CLR_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);
	OCR0 = COMPARE_TIMER;

#elif		MODE == PWM_FAST
	SET_BIT(TCCR0,6);
	SET_BIT(TCCR0,3);

#if PWM_MODE == NON_INVERTING
	CLR_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);

#else
	SET_BIT(TCCR0, 4);
	SET_BIT(TCCR0, 5);

#endif

#endif

	vSet_Prescaler();
	TCNT0 = START_TIMER;

}

void vTimer0_Check_OVF(void){
	while((TIFR & 0x01) == 0);
	TCNT0 = START_TIMER;
	TIFR = 0x01;
}

void vTimer0_Interrupt_Enable(void){
#if MODE == NORMAL_MODE
	SET_BIT(TIMSK,0);
#elif MODE == CTC
	SET_BIT(TIMSK,1);
#endif
}

void Timer0_u8SetStart(uint8 start_time){
	TCNT0 = start_time;
}

void Timer0_vStop(void){
	TCCR0 = 0x00;
}

void Timer0_u8SetComp(uint8 comp_time){
	OCR0 = comp_time;
}

void Timer0_vSetPWMDutyCycleFast(uint8 duty){

	if (duty <= 100) {
		#if PWM_MODE == NON_INVERTING
			Timer0_u8SetComp(((duty*256)/100) - 1);

		#else
			Timer0_u8SetComp(((100 - duty)*256)/100 - 1);
		#endif
	}
}


void Timer0_vSetPWMDutyCyclePhaseCorrect(uint8 duty){
	if (duty <= 100) {
		#if PWM_MODE == NON_INVERTING
			Timer0_u8SetComp(((duty*510)/200) - 1);

		#else
			Timer0_u8SetComp(((100 - duty)*510)/200 - 1);
		#endif
	}
}




static void vSet_Prescaler(void){
#if			PRESCALER == NO_PRESCALER
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
#elif 		PRESCALER == PRESCALER_8
	CLR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
#elif		PRESCALER == PRESCALER_64
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLR_BIT(TCCR0,2);
#elif		PRESCALER == PRESCALER_256
	CLR_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#elif		PRESCALER == PRESCALER_1024
	SET_BIT(TCCR0,0);
	CLR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
#endif
}

void Timer0_pfSetCallback(void (*p2fvar)(void)){
	p2f = p2fvar;
}

ISR(TIMER0_OVF_vect){
	if(p2f != NULL){
		p2f();
	}
}

ISR(TIMER0_COMP_vect){
	if(p2f != NULL){
		p2f();
	}
}
