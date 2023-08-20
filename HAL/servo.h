/*
 * servo.h
 *
 *  Created on: Aug 2, 2023
 *      Author: larar
 */

#ifndef HAL_SERVO_H_
#define HAL_SERVO_H_

#include "../UTILS/STD_TYPES.h"

#define SERVO_FREQUENCY 100
#define DUTY(ANGLE)		(2.5/90)*ANGLE + 7.5

void Servo_vOn (sint8 angle);
void Servo_vOff(void);


#endif /* HAL_SERVO_H_ */
