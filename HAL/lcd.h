/*
 * lcd.h
 *
 *  Created on: Jul 23, 2023
 *      Author: larar
 */

#ifndef HAL_LCD_H_
#define HAL_LCD_H_

#include <util/delay.h>
#include "../UTILS/STD_TYPES.h"
#include "../UTILS/MACROS.h"
#include "../MCAL/DIO_TYPES.h"
#include "../MCAL/dio.h"



void LCD_vInit(void);
void LCD_vSendCmnd(uint8 cmnd);
void LCD_vSendData(uint8 data);
void LCD_vSendString(uint8* str);
void LCD_vSendInt(sint32 num);
void LCD_vGoTo(uint8 row , uint8 col);
static void vPriWriteHalfPort(uint8 value);
static void vPriEnable(void);

#endif /* HAL_LCD_H_ */
