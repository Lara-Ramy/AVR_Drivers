/*
 * SPI.c
 *
 *  Created on: Aug 6, 2023
 *      Author: larar
 */

#include "REGISTERS.h"
#include "../UTILS/MACROS.h"
#include "SPI.h"
#include "SPI_config.h"
#include "SPI_priv.h"
#include <string.h>

void(*SPI_pCallBack)(uint8 dataIn);


void SPI_vInit(void){
#if DATA_ORDER == DATA_ORDER_LSB
	SET_BIT(SPCR,5);
#elif DATA_ORDER == DATA_ORDER_MSB
	CLR_BIT(SPCR,5);
#endif


#if CLOCK_POLARITY == CLOCK_POLARITY_FALLING
	SET_BIT(SPCR,3);
#elif CLOCK_POLARITY == CLOCK_POLARITY_RISING
	CLR_BIT(SPCR,3);
#endif

#if CLOCK_PHASE == CLOCK_PHASE_SAMPLE
	CLR_BIT(SPCR,2);
#elif CLOCK_PHASE == CLOCK_PHASE_SETUP
	SET_BIT(SPCR,2);
#endif



#if SPI_MODE == SPI_MODE_MASTER
	SET_BIT(SPCR,4);

#if FREQUENCY == FREQUENCY_4
	CLR_BIT(SPCR,0);
	CLR_BIT(SPCR,1);
	CLR_BIT(SPSR,0);
#elif FREQUENCY == FREQUENCY_16
	SET_BIT(SPCR,0);
	CLR_BIT(SPCR,1);
	CLR_BIT(SPSR,0);
#elif FREQUENCY == FREQUENCY_64
	CLR_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	CLR_BIT(SPSR,0);
#elif FREQUENCY == FREQUENCY_128
	SET_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	CLR_BIT(SPSR,0);
#elif FREQUENCY == FREQUENCY_2
	CLR_BIT(SPCR,0);
	CLR_BIT(SPCR,1);
	SET_BIT(SPSR,0);
#elif FREQUENCY == FREQUENCY_8
	SET_BIT(SPCR,0);
	CLR_BIT(SPCR,1);
	SET_BIT(SPSR,0);
#elif FREQUENCY == FREQUENCY_32
	CLR_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	SET_BIT(SPSR,0);
#elif FREQUENCY == FREQUENCY_64
	SET_BIT(SPCR,0);
	SET_BIT(SPCR,1);
	SET_BIT(SPSR,0);
#endif

#elif SPI_MODE == SPI_MODE_SLAVE
	CLR_BIT(SPCR,4);
#endif

	SET_BIT(SPCR, 6);
}

uint8 SPI_u8TransmitReceive(uint8 data){
	while(GET_BIT(SPSR, 6) == 1);
	SPDR = data;
	while(GET_BIT(SPSR, 7) == 0);
	return SPDR;
}

void SPI_vTransmitAsynch(uint8 data, void(*p2f)(uint8 dataIn)){
	SET_BIT(SPCR, 7);
	while(GET_BIT(SPSR, 6) == 1);
	SPDR = data;
	SPI_pCallBack = p2f;
}

void __vector_12(void) __attribute__((signal));
void __vector_12(void){
	if (SPI_pCallBack != NULL){
		SPI_pCallBack(SPDR);
	}
}


