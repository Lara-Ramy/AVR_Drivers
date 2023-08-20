
#include "UTILS/STD_TYPES.h"
#include "MCAL/dio_config.h"
#include "MCAL/dio.h"
#include "MCAL/timer0.h"
#include <string.h>
#include "RTOS/RTOS.h"
#include "MCAL/general_interrupt.h"


void ToggleLED1(void){
	DIO_Toggle(PA0);
}

void ToggleLED2(void){
	DIO_Toggle(PA1);
}

void ToggleLED3(void){
	DIO_Toggle(PA2);
}


int main(void){

	DIO_init();
	GI_vEnable();

	create_task(1, 0, ToggleLED1);
	create_task(2, 1, ToggleLED2);
	create_task(3, 2, ToggleLED3);
	start_OS();


	while(1){

	}
}
