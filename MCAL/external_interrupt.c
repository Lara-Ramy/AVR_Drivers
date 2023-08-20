/*
 * external_interrupt.c
 *
 *  Created on: Jul 24, 2023
 *      Author: larar
 */


#include "external_interrupt.h"
#include "../UTILS/MACROS.h"
#include "REGISTERS.h"

void EXTI_vEnable(EXTI_source source, trigger_type trigger){
	switch(source){
	case EXTI0:
		if (trigger == RISING_EDGE){
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);

		}
		else if (trigger == FALLING_EDGE){
			CLR_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
		}
		else if (trigger == LOW_EDGE){
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		}
		else{
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
		}
		CLR_BIT(DDRD, 2);
		SET_BIT(PORTD, 2);

		SET_BIT(GICR, 6);
		break;
	case EXTI1:
		if (trigger == RISING_EDGE){
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
		else if (trigger == FALLING_EDGE){
			CLR_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
		}
		else if (trigger == LOW_EDGE){
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		}
		else{
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
		}
		CLR_BIT(DDRD, 3);
		SET_BIT(PORTD, 3);

		SET_BIT(GICR, 7);
		break;
	case EXTI2:
		if (trigger == RISING_EDGE){
			SET_BIT(MCUCSR,6);
		}
		else if (trigger == FALLING_EDGE){
			CLR_BIT(MCUCSR,6);
		}
		CLR_BIT(DDRB, 2);
		SET_BIT(PORTB, 2);

		SET_BIT(GICR, 5);
		break;

	}
}

void EXTI_vDisable(EXTI_source source){
	switch(source){
	case EXTI0:
		CLR_BIT(GICR, 6);
		break;
	case EXTI1:
		CLR_BIT(GICR, 7);
		break;
	case EXTI2:
		CLR_BIT(GICR, 5);
		break;

	}
}
