/*
 * watchdog.c
 *
 *  Created on: Jul 31, 2023
 *      Author: larar
 */

#include "watchdog.h"
#include "REGISTERS.h"
#include "../UTILS/MACROS.h"
#include "../UTILS/STD_TYPES.h"

void Watchdog_vInit(void){
	SET_BIT(WDTCR,3);
}

void Watchdog_vStart(times t){
	WDTCR &= (0b11111000);
	WDTCR |= t;
}

void Watchdog_vDisable(void){
	WDTCR = (1 << 4) | (1 << 3);
	WDTCR = 0x00;
}
