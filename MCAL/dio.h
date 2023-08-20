/*
 * dio.h
 *
 *  Created on: Jul 22, 2023
 *      Author: larar
 */

#ifndef MCAL_DIO_H_
#define MCAL_DIO_H_
#include "../UTILS/STD_TYPES.h"
#include "DIO_TYPES.h"

void DIO_WriteChannel(pin_channel_type channel, pin_channel_status status);

uint8 DIO_ReadChannel(pin_channel_type channel);

void DIO_SetInternalPullup(pin_channel_type channel, pin_channel_status status);

void DIO_Toggle(pin_channel_type channel);

#endif /* MCAL_DIO_H_ */
