/*
 * dio.c
 *
 *  Created on: Jul 22, 2023
 *      Author: larar
 */

#include "dio.h"
#include "DIO_TYPES.h"
#include "REGISTERS.h"
#include "../UTILS/MACROS.h"
#include "../UTILS/STD_TYPES.h"

void DIO_WriteChannel(pin_channel_type channel, pin_channel_status status){
	switch (channel / PORT_SIZE){
	case PA:
		if (status == HIGH){
			SET_BIT((PORTA),(channel%PORT_SIZE));
		}
		else{
			CLR_BIT((PORTA),(channel%PORT_SIZE));
		}
		break;
	case PB:
		if (status == HIGH){
			SET_BIT((PORTB),(channel%PORT_SIZE));
		}
		else{
			CLR_BIT((PORTB),(channel%PORT_SIZE));
		}
		break;
	case PC:
		if (status == HIGH){
			SET_BIT((PORTC),(channel%PORT_SIZE));
		}
		else{
			CLR_BIT((PORTC),(channel%PORT_SIZE));
		}
		break;
	case PD:
		if (status == HIGH){
			SET_BIT((PORTD),(channel%PORT_SIZE));
		}
		else{
			CLR_BIT((PORTD),(channel%PORT_SIZE));
		}
		break;
	}
}

pin_channel_status DIO_ReadChannel(pin_channel_type channel){
	switch (channel / PORT_SIZE){
	case PA:
		return GET_BIT((PINA),(channel%PORT_SIZE));
	case PB:
		return GET_BIT((PINB),(channel%PORT_SIZE));
	case PC:
		return GET_BIT((PINC),(channel%PORT_SIZE));
	case PD:
		return GET_BIT((PIND),(channel%PORT_SIZE));
	}
}

void DIO_SetInternalPullup(pin_channel_type channel, pin_channel_status status){
	switch (channel / PORT_SIZE){
	case PA:
		if (status == HIGH){
			SET_BIT((PORTA),(channel%PORT_SIZE));
		}
		else{
			CLR_BIT((PORTA),(channel%PORT_SIZE));
		}
		break;
	case PB:
		if (status == HIGH){
			SET_BIT((PORTB),(channel%PORT_SIZE));
		}
		else{
			CLR_BIT((PORTB),(channel%PORT_SIZE));
		}
		break;
	case PC:
		if (status == HIGH){
			SET_BIT((PORTC),(channel%PORT_SIZE));
		}
		else{
			CLR_BIT((PORTC),(channel%PORT_SIZE));
		}
		break;
	case PD:
		if (status == HIGH){
			SET_BIT((PORTD),(channel%PORT_SIZE));
		}
		else{
			CLR_BIT((PORTD),(channel%PORT_SIZE));
		}
		break;
		}
}

void DIO_Toggle(pin_channel_type channel){
	switch (channel / PORT_SIZE){
		case PA:
			TOGGLE_BIT((PORTA),(channel%PORT_SIZE));
			break;
		case PB:
			TOGGLE_BIT((PORTB),(channel%PORT_SIZE));
			break;
		case PC:
			TOGGLE_BIT((PORTC),(channel%PORT_SIZE));
			break;
		case PD:
			TOGGLE_BIT((PORTD),(channel%PORT_SIZE));
			break;
		}
}
