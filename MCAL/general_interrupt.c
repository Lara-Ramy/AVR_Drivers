/*
 * general_interrupt.c
 *
 *  Created on: Jul 24, 2023
 *      Author: larar
 */

#include "general_interrupt.h"
#include "REGISTERS.h"
#include "../UTILS/MACROS.h"

void GI_vEnable(void)
{
	SET_BIT(SREG, 7);
}
void GI_vDisable(void){
	CLR_BIT(SREG, 7);
}
