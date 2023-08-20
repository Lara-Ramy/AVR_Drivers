/*
 * keypad.h
 *
 *  Created on: Jul 23, 2023
 *      Author: larar
 */

#ifndef HAL_KEYPAD_H_
#define HAL_KEYPAD_H_
#include "../UTILS/STD_TYPES.h"

#define KEY_NOT_PRESSED 0xff

void Keypad_vInit(void);

uint8 Keypad_u8GetPressed(void);

#endif /* HAL_KEYPAD_H_ */
