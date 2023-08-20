/*
 * dio_config.h
 *
 *  Created on: Jul 22, 2023
 *      Author: larar
 */

#ifndef MCAL_DIO_CONFIG_H_
#define MCAL_DIO_CONFIG_H_
#include "dio.h"
#include "DIO_TYPES.h"


#define NUM_OF_DIO 4

void DIO_init();


typedef struct {
	port_type port;
	pin_type pin;
	dir_type dir;

}pin_config_t;

#endif /* MCAL_DIO_CONFIG_H_ */
