/*
 * buzzer.c
 *
 *  Created on: Aug 4, 2023
 *      Author: larar
 */

#include "buzzer.h"
#include "buzzer_config.h"
#include "../MCAL/dio.h"

void BUZZER_vOn(void){
	DIO_WriteChannel(BUZZER, HIGH);
}

void BUZZER_vOff(void){
	DIO_WriteChannel(BUZZER, LOW);
}
