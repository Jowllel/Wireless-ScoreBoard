/**
 ******************************************************************************
 * @file        bms.c
 * @author      jschaller
 * @date        25.04.2024
 * @version     1.0
 * @brief       all functions for the battery and power management.
 ******************************************************************************
 */

#include "bms.h"

extern ADC_HandleTypeDef hadc1;


void bms_enPwr(bool enable)
{
	if(enable) 	HAL_GPIO_WritePin(PWR_EN_GPIO_Port, PWR_EN_Pin, 1);
	else		HAL_GPIO_WritePin(PWR_EN_GPIO_Port, PWR_EN_Pin, 0);
}


double bms_getBatVoltage(void)
{
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 1);
	double voltage_V = HAL_ADC_GetValue(&hadc1) * 3.1 * 2 / ((1<<12) - 1);
	return voltage_V;
}

uint8_t bms_getBatPercent(void)
{
	 int16_t foo =  (int16_t)(bms_getBatVoltage() * 100);
	 int16_t batPercent = foo - 320;
	 if(batPercent < 0) batPercent = 0;
	 if(batPercent > 100) batPercent = 100;
	 return (uint8_t)(batPercent);
}

bool bms_getChargingState(void)
{
	return !HAL_GPIO_ReadPin(BMS_CHG_GPIO_Port, BMS_CHG_Pin);
}



