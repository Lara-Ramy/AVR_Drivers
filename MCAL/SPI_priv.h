/*
 * SPI_priv.h
 *
 *  Created on: Aug 6, 2023
 *      Author: larar
 */

#ifndef MCAL_SPI_PRIV_H_
#define MCAL_SPI_PRIV_H_

#define DATA_ORDER_LSB			1
#define DATA_ORDER_MSB			2

#define CLOCK_POLARITY_RISING	1
#define CLOCK_POLARITY_FALLING	2

#define CLOCK_PHASE_SAMPLE		1
#define CLOCK_PHASE_SETUP		2

#define FREQUENCY_4				1
#define FREQUENCY_16			2
#define FREQUENCY_64			3
#define FREQUENCY_128			4
#define FREQUENCY_2				5
#define FREQUENCY_8				6
#define FREQUENCY_32			7
#define FREQUENCY_64			8

#define SPI_MODE_MASTER			1
#define SPI_MODE_SLAVE			2

#endif /* MCAL_SPI_PRIV_H_ */
