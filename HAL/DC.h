/*
 * DC.h
 *
 *  Created on: Aug 1, 2023
 *      Author: larar
 */

#ifndef HAL_DC_H_
#define HAL_DC_H_

#include "../UTILS/STD_TYPES.h"


#define DC_CLOCK_WISE                   1
#define DC_COUNTER_CLOCK_WISE           2

#define DIR_PIN							PB5
#define ENABLE_PIN						PB6
#define PWM_PIN							PB3


void DC_vInit(void);
void DC_vOn(uint8 direction);
void DC_vControlSpeed(uint8 speed);
void DC_vOff(void);

#endif /* HAL_DC_H_ */
