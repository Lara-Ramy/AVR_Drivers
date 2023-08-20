/*
 * servo.c
 *
 *  Created on: Aug 2, 2023
 *      Author: larar
 */

#include "servo.h"
#include "../MCAL/timer1.h"


void Servo_vOn (sint8 angle){
	Timer1_vInit();

	uint8 duty = DUTY(angle);
	Timer1_SetPWMFast(duty, 100);
	Timer1_vStart(0);
}

void Servo_vOff(void){
	Timer1_vStop();
}
