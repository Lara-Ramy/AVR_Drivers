/*
 * seven_seg.h
 *
 *  Created on: Jul 22, 2023
 *      Author: larar
 */

#ifndef HAL_SEVEN_SEG_H_
#define HAL_SEVEN_SEG_H_

#include "../MCAL/dio_config.h"

void Segment_Init();
void Segment_Write(uint8 num);

#endif /* HAL_SEVEN_SEG_H_ */
