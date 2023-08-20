/*
 * DIO_TYPES.h
 *
 *  Created on: Jul 22, 2023
 *      Author: larar
 */

#ifndef MCAL_DIO_TYPES_H_
#define MCAL_DIO_TYPES_H_

typedef enum DIO_TYPES {
	PA0,
	PA1,
	PA2,
	PA3,
	PA4,
	PA5,
	PA6,
	PA7,

	PB0,
	PB1,
	PB2,
	PB3,
	PB4,
	PB5,
	PB6,
	PB7,

	PC0,
	PC1,
	PC2,
	PC3,
	PC4,
	PC5,
	PC6,
	PC7,

	PD0,
	PD1,
	PD2,
	PD3,
	PD4,
	PD5,
	PD6,
	PD7
} pin_channel_type;

typedef enum{
	LOW,
	HIGH
}pin_channel_status;

typedef enum{
	PA, PB, PC, PD
}port_type;

typedef enum{
	P0,
	P1,
	P2,
	P3,
	P4,
	P5,
	P6,
	P7
}pin_type;

typedef enum{
	DIO_INPUT,
	DIO_OUTPUT
}dir_type;

//#define PA 0;
//#define PB 1;
//#define PC 2;
//#define PD 3;

#define PORT_SIZE 8

#endif /* MCAL_DIO_TYPES_H_ */
