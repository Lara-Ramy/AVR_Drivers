/*
 * SPI.h
 *
 *  Created on: Aug 6, 2023
 *      Author: larar
 */

#ifndef MCAL_SPI_H_
#define MCAL_SPI_H_

#include "../UTILS/STD_TYPES.h"

void SPI_vInit(void);

uint8 SPI_u8TransmitReceive(uint8 data);

void SPI_vTransmitAsynch(uint8 data, void(*p2f)(uint8 dataIn));



#endif /* MCAL_SPI_H_ */
