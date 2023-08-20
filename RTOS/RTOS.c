/*
 * RTOS.c
 *
 *  Created on: Aug 18, 2023
 *      Author: larar
 */
#include "../UTILS/STD_TYPES.h"
#include "../MCAL/dio_config.h"
#include "../MCAL/dio.h"
#include "../MCAL/timer0.h"
#include "RTOS.h"

#include <string.h>

volatile uint16 tick_time = 0;
volatile uint16 counter = 0;


task tasks[3];

void start_OS(){
	vTimer0_Interrupt_Enable();
	Timer0_pfSetCallback(Increment_tickTime);
	vTimer0_init();
}

void create_task(uint8 periodicity, uint8 priority, void (*ptr)(void)){
	tasks[priority].periodicity = periodicity;
	tasks[priority].ptf = ptr;
//	Timer0_pfSetCallback(Increment_tickTime);
}

void schedular(void){
	task exe[3];
	for(uint8 i = 0; i < 3; i++){
		if(tick_time%tasks[i].periodicity == 0){
			exe[i].ptf = tasks[i].ptf;
		}
		else{
			exe[i].ptf = NULL;
		}
	}

	for (uint8 i = 0; i < 3; i++){
		if(exe[i].ptf != NULL){
			exe[i].ptf();
		}
	}
}


void Increment_tickTime(void){
	DIO_Toggle(PA5);
	counter++;
	if(counter == 100){
		counter = 0;
		tick_time++;
		schedular();

	}
}
