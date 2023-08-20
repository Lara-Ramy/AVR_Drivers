/*
 * dio_config.c
 *
 *  Created on: Jul 22, 2023
 *      Author: larar
 */


#include "dio_config.h"
#include "REGISTERS.h"
#include "../UTILS/MACROS.h"

pin_config_t pin_cfgs[] = {
//		// LCD
//		{PA,P3,DIO_OUTPUT},
//		{PA,P2,DIO_OUTPUT},
//		{PB,P0,DIO_OUTPUT},
//		{PB,P1,DIO_OUTPUT},
//		{PB,P2,DIO_OUTPUT},
//		{PB,P4,DIO_OUTPUT},
//		//USART
//		{PD,P0,DIO_INPUT},
//		{PD,P1,DIO_OUTPUT},
//		//keypad
//		{PC,P5,DIO_OUTPUT},
//		{PC,P4,DIO_OUTPUT},
//		{PC,P3,DIO_OUTPUT},
//		{PC,P2,DIO_OUTPUT},
//		{PD,P7,DIO_INPUT},
//		{PD,P6,DIO_INPUT},
//		{PD,P5,DIO_INPUT},
//		{PD,P3,DIO_INPUT},
		//LCD Red
		//{PB,P7,DIO_OUTPUT}
		//LCD Green
//		{PA,P4,DIO_OUTPUT}
		//SPI
//		{PB,P4,DIO_OUTPUT},
//		{PB,P5,DIO_OUTPUT},
//		{PB,P6,DIO_INPUT},
//		{PB,P7,DIO_OUTPUT}
		{PA,P0,DIO_OUTPUT},
		{PA,P1,DIO_OUTPUT},
		{PA,P2,DIO_OUTPUT},
		{PA,P6,DIO_OUTPUT}
};


void DIO_init(){
	for(int i = 0; i < (sizeof(pin_cfgs)/ sizeof(pin_cfgs[0])); i++){
		switch(pin_cfgs[i].port){
		case PA:
			if(pin_cfgs[i].dir == DIO_OUTPUT){
				SET_BIT(DDRA, pin_cfgs[i].pin);
			}
			else{
				CLR_BIT(DDRA, pin_cfgs[i].pin);
			}
		break;
		case PB:
			if(pin_cfgs[i].dir == DIO_OUTPUT){
				SET_BIT(DDRB, pin_cfgs[i].pin);
			}
			else{
				CLR_BIT(DDRB, pin_cfgs[i].pin);
			}
			break;
		case PC:
			if(pin_cfgs[i].dir == DIO_OUTPUT){
				SET_BIT(DDRC, pin_cfgs[i].pin);
			}
			else{
				CLR_BIT(DDRC, pin_cfgs[i].pin);
			}
		break;
		case PD:
			if(pin_cfgs[i].dir == DIO_OUTPUT){
				SET_BIT(DDRD, pin_cfgs[i].pin);
			}
			else{
				CLR_BIT(DDRD, pin_cfgs[i].pin);
			}
		break;
		}
	}
}

