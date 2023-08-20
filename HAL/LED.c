/*
 * LED.c
 *
 *  Created on: Aug 4, 2023
 *      Author: larar
 */

#include "LED_config.h"
#include "LED.h"
#include "../MCAL/dio.h"


void LED_vRedOn(void){
	DIO_WriteChannel(RED_LED, HIGH);
}

void LED_vRedOff(void){
	DIO_WriteChannel(RED_LED, LOW);
}

void LED_vGreenOn(void){
	DIO_WriteChannel(GREEN_LED, HIGH);
}


void LED_vGreenOff(void){
	DIO_WriteChannel(GREEN_LED, LOW);
}

void LED_vBlueOn(void){
	DIO_WriteChannel(BLUE_LED, HIGH);
}

void LED_vBlueOff(void){
	DIO_WriteChannel(BLUE_LED, LOW);
}

void LED_vYellowOn(void){
	DIO_WriteChannel(YELLOW_LED, HIGH);
}

void LED_vYellowOff(void){
	DIO_WriteChannel(YELLOW_LED, LOW);
}
