/**
 ******************************************************************************
 * @file        bms.h
 * @author      jschaller
 * @date        25.04.2024
 * @version     1.0
 * @brief       all functions for the battery and power management.
 ******************************************************************************
 */

#ifndef USER_BMS_H_
#define USER_BMS_H_

#include "main.h"

void bms_enPwr(bool enable);
double bms_getBatVoltage(void);
uint8_t bms_getBatPercent(void);

#endif /* USER_BMS_H_ */
