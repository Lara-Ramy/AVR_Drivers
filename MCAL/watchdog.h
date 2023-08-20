/*
 * watchdog.h
 *
 *  Created on: Jul 31, 2023
 *      Author: larar
 */

#ifndef MCAL_WATCHDOG_H_
#define MCAL_WATCHDOG_H_

typedef enum{
	T_163ms, T_325ms, T_65ms, T_013s, T_026s, T_052s, T_1s, T_21ms
}times;



void Watchdog_vInit(void);

void Watchdog_vStart(times t);

void Watchdog_vDisable(void);


#endif /* MCAL_WATCHDOG_H_ */
