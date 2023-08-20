/*
 * ICU.c
 *
 *  Created on: Jul 31, 2023
 *      Author: larar
 */


#include "../UTILS/STD_TYPES.h"
#include "../UTILS/MACROS.h"
#include "REGISTERS.h"

#include "ICU.h"
#include "ICU_config.h"
#include <string.h>

volatile static uint16 on_period;
volatile static uint16 off_period;
volatile static uint16 old_val = 0;


void ICU_vInit(void){
	CLR_BIT(TCCR1A,0);
	CLR_BIT(TCCR1A,1);
	CLR_BIT(TCCR1B,3);
	CLR_BIT(TCCR1B,4);


#if EDGE == RISING_EDGE_ICU
	SET_BIT(TCCR1B, 6);
#elif EDGE == FALLING_EDGE_ICU
	CLR_BIT(TCCR1B, 6);
#endif

//	TIMSK

}

void ICU_vGetDutyCycle(uint8 *duty){
	if(duty != NULL){
		*duty = on_period*100/(on_period + off_period);
	}
}

void ICU_vGetFrequency(uint32 *frequency){
	if(frequency != NULL){
		*frequency = 1000000/(on_period + off_period);
	}
}

void __vector_6(void) __attribute__ ((signal));
void __vector_6(void){
	static uint8 edge_flag = EDGE;
	uint16 counter_val = ICR1;

	if(edge_flag == RISING_EDGE_ICU){
		off_period = (counter_val - old_val) * 4;
		CLR_BIT(TCCR1B, 6);
		edge_flag = FALLING_EDGE_ICU;
	}
	else if(edge_flag == FALLING_EDGE_ICU){
		on_period = (counter_val - old_val) * 4;
		SET_BIT(TCCR1B, 6);
		edge_flag = RISING_EDGE_ICU;
	}
	old_val = counter_val;
}
