/*
 * DC.c
 *
 *  Created on: Aug 1, 2023
 *      Author: larar
 */

#include "DC.h"
#include "../MCAL/dio.h"
#include "../MCAL/timer0.h"


void DC_vInit(void){
	vTimer0_init();
}


void DC_vOn(uint8 direction){
	DIO_WriteChannel(ENABLE_PIN, HIGH);

	if (direction == DC_CLOCK_WISE){
		DIO_WriteChannel(DIR_PIN, HIGH);
	}
	else if (direction == DC_COUNTER_CLOCK_WISE){
		DIO_WriteChannel(DIR_PIN, LOW);
	}

}

void DC_vControlSpeed(uint8 speed){
		Timer0_vSetPWMDutyCycleFast(speed);

}

void DC_vOff(void){
	DIO_WriteChannel(ENABLE_PIN, LOW);
}


