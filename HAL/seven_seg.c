/*
 * seven_seg.c
 *
 *  Created on: Jul 22, 2023
 *      Author: larar
 */


#include "seven_seg.h"
#include "../MCAL/dio_config.h"

void Segment_Init()
{

	DIO_init();

}

void Segment_Write(uint8 num){
	DIO_WriteChannel(PA3, LOW);
	DIO_WriteChannel(PA2, LOW);
	DIO_WriteChannel(PB5, LOW);
	DIO_WriteChannel(PB6, LOW);



	DIO_WriteChannel(PB0, LOW);

	DIO_WriteChannel(PB1, LOW);

	DIO_WriteChannel(PB2, LOW);

	DIO_WriteChannel(PB4, LOW);

}

