/*
 * USART.c
 *
 *  Created on: Aug 5, 2023
 *      Author: larar
 */


#include "USART.h"
#include "USART_config.h"
#include "REGISTERS.h"
#include "../UTILS/STD_TYPES.h"
#include "../UTILS/MACROS.h"


void USART_vInit(void){

	uint32 buad = USART_BAUD_RATE;
	uint32 UBBR_val;
	uint8 UCSRC_val = 0b10000000;

#if USART_MODE == ASYNCHRONOUS
	CLR_BIT(UCSRC_val,6);
#if USART_SPEED	== USART_SPEED_NORMAL
	CLR_BIT(UCSRA, 1);
	UBBR_val = F /(16*buad) - 1;

#elif USART_SPEED	== USART_SPEED_DOUBLE
	SET_BIT(UCSRA, 1);
	UBBR_val = F_CPU/(8*buad) - 1;
#endif

#elif USART_MODE == SYNCHRONOUS
	SET_BIT(UCSRC_val,6);
	UBBR_val = F_CPU/(2*buad) - 1;

#if USART_CLK_EDGE == USART_CLK_RISING
	UCSRC |= 0b11000001;
	SET_BIT(UCSRC_val, 1);
#elif USART_CLK_EDGE == USART_CLK_FALLING
	CLR_BIT(UCSRC_val,0);
#endif
#endif

#if USART_PARITY == USART_PARITY_DISABLED
	CLR_BIT(UCSRC_val, 4);
	CLR_BIT(UCSRC_val, 5);

#elif USART_PARITY == USART_PARITY_EVEN
	CLR_BIT(UCSRC_val, 4);
	SET_BIT(UCSRC_val, 5);

#elif USART_PARITY == USART_PARITY_ODD
	SET_BIT(UCSRC_val, 4);
	SET_BIT(UCSRC_val, 5);

#endif

#if USART_STOP_BITS == USART_1_STOP_BIT
	CLR_BIT(UCSRC_val, 3);
#elif USART_STOP_BITS == USART_2_STOP_BITS
	SET_BIT(UCSRC_val, 3);
#endif

#if USART_BIT_SIZE == USART_5_BIT
	UCSRC |= 0b10000000;
#elif USART_BIT_SIZE == USART_6_BIT
	UCSRC |= 0b10000010;
#elif USART_BIT_SIZE == USART_7_BIT
	UCSRC |= 0b10000100;
#elif USART_BIT_SIZE == USART_8_BIT
	SET_BIT(UCSRC_val, 2);
	SET_BIT(UCSRC_val, 1);
#elif USART_BIT_SIZE == USART_9_BIT
	UCSRC |= 0b10001110;
#endif

	UBRRH = (uint8)(UBBR_val >> 8);
	UBRRL = (uint8)(UBBR_val);

	SET_BIT( UCSRB , 3 );
	SET_BIT( UCSRB , 4 );

	UCSRC = UCSRC_val;

}

uint16 USART_u16Receive(void){
	while(GET_BIT( UCSRA , 7 ) == 0);

//	CLR_BIT(UCSRA, 7);

	return UDR;
}

void USART_vTransmit(uint8 data){
	while(GET_BIT(UCSRA,5) == 0);
	UDR = data;
}

