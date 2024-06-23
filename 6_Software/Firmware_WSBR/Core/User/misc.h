/**
 ******************************************************************************
 * @file        misc.h
 * @author      jschaller
 * @date        25.04.2024
 * @version     1.0
 * @brief       all misc functions for rgb led, vibration motor etc.
 ******************************************************************************
 */

#ifndef USER_MISC_H_
#define USER_MISC_H_

#include "main.h"


typedef enum
{
	P0_SOURCE, P25_SOURCE, P50_SOURCE, P75_SOURCE, P100_SOURCE, P0_CHARGING, P25_CHARGING, P50_CHARGING, P75_CHARGING, P100_CHARGING, P0
} BatLedStateEnum;


void setBatLed(BatLedStateEnum state);


#endif /* USER_MISC_H_ */
