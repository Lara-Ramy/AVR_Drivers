/*
 * USART.h
 *
 *  Created on: Aug 5, 2023
 *      Author: larar
 */

#ifndef MCAL_USART_H_
#define MCAL_USART_H_

#include "../UTILS/STD_TYPES.h"


#define ASYNCHRONOUS			1
#define SYNCHRONOUS				2

#define USART_PARITY_DISABLED	1
#define USART_PARITY_EVEN		2
#define USART_PARITY_ODD		3

#define USART_1_STOP_BIT		1
#define USART_2_STOP_BITS		2

#define USART_5_BIT				1
#define USART_6_BIT				2
#define USART_7_BIT				3
#define USART_8_BIT				4
#define USART_9_BIT				5

#define USART_CLK_RISING		1
#define USART_CLK_FALLING		2

#define USART_SPEED_NORMAL		1
#define USART_SPEED_DOUBLE		2

#define UBRR_CALC(F,B)			(F/(16*B)) - 1


void USART_vInit(void);

uint16 USART_u16Receive(void);

void USART_vTransmit(uint8 data);

#endif /* MCAL_USART_H_ */
