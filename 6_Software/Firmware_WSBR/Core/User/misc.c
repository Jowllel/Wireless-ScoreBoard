/**
 ******************************************************************************
 * @file        misc.c
 * @author      jschaller
 * @date        25.04.2024
 * @version     1.0
 * @brief       all misc functions for rgb led, vibration motor etc.
 ******************************************************************************
 */

#include "misc.h"

uint32_t oldTick = 500;
bool b;


void setBatLed(BatLedStateEnum state)
{
	if((HAL_GetTick() - oldTick) >= 500)
	{
		oldTick = HAL_GetTick();
		b = !b;
	}

	switch(state)
	{
	case P0_SOURCE:
		HAL_GPIO_WritePin(PWR_LED4_GPIO_Port, PWR_LED4_Pin, b);
		HAL_GPIO_WritePin(PWR_LED3_GPIO_Port, PWR_LED3_Pin, 0);
		HAL_GPIO_WritePin(PWR_LED2_GPIO_Port, PWR_LED2_Pin, 0);
		HAL_GPIO_WritePin(PWR_LED1_GPIO_Port, PWR_LED1_Pin, 0);

		break;
	case P25_SOURCE:
		HAL_GPIO_WritePin(PWR_LED4_GPIO_Port, PWR_LED4_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED3_GPIO_Port, PWR_LED3_Pin, 0);
		HAL_GPIO_WritePin(PWR_LED2_GPIO_Port, PWR_LED2_Pin, 0);
		HAL_GPIO_WritePin(PWR_LED1_GPIO_Port, PWR_LED1_Pin, 0);

		break;
	case P50_SOURCE:
		HAL_GPIO_WritePin(PWR_LED4_GPIO_Port, PWR_LED4_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED3_GPIO_Port, PWR_LED3_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED2_GPIO_Port, PWR_LED2_Pin, 0);
		HAL_GPIO_WritePin(PWR_LED1_GPIO_Port, PWR_LED1_Pin, 0);

		break;
	case P75_SOURCE:
		HAL_GPIO_WritePin(PWR_LED4_GPIO_Port, PWR_LED4_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED3_GPIO_Port, PWR_LED3_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED2_GPIO_Port, PWR_LED2_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED1_GPIO_Port, PWR_LED1_Pin, 0);

		break;
	case P100_SOURCE:
		HAL_GPIO_WritePin(PWR_LED4_GPIO_Port, PWR_LED4_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED3_GPIO_Port, PWR_LED3_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED2_GPIO_Port, PWR_LED2_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED1_GPIO_Port, PWR_LED1_Pin, 1);

		break;
	case P0_CHARGING:
		HAL_GPIO_WritePin(PWR_LED4_GPIO_Port, PWR_LED4_Pin, b);
		HAL_GPIO_WritePin(PWR_LED3_GPIO_Port, PWR_LED3_Pin, 0);
		HAL_GPIO_WritePin(PWR_LED2_GPIO_Port, PWR_LED2_Pin, 0);
		HAL_GPIO_WritePin(PWR_LED1_GPIO_Port, PWR_LED1_Pin, 0);

		break;
	case P25_CHARGING:
		HAL_GPIO_WritePin(PWR_LED4_GPIO_Port, PWR_LED4_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED3_GPIO_Port, PWR_LED3_Pin, b);
		HAL_GPIO_WritePin(PWR_LED2_GPIO_Port, PWR_LED2_Pin, 0);
		HAL_GPIO_WritePin(PWR_LED1_GPIO_Port, PWR_LED1_Pin, 0);

		break;
	case P50_CHARGING:
		HAL_GPIO_WritePin(PWR_LED4_GPIO_Port, PWR_LED4_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED3_GPIO_Port, PWR_LED3_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED2_GPIO_Port, PWR_LED2_Pin, b);
		HAL_GPIO_WritePin(PWR_LED1_GPIO_Port, PWR_LED1_Pin, 0);

		break;
	case P75_CHARGING:
		HAL_GPIO_WritePin(PWR_LED4_GPIO_Port, PWR_LED4_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED3_GPIO_Port, PWR_LED3_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED2_GPIO_Port, PWR_LED2_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED1_GPIO_Port, PWR_LED1_Pin, b);

		break;
	case P100_CHARGING:
		HAL_GPIO_WritePin(PWR_LED4_GPIO_Port, PWR_LED4_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED3_GPIO_Port, PWR_LED3_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED2_GPIO_Port, PWR_LED2_Pin, 1);
		HAL_GPIO_WritePin(PWR_LED1_GPIO_Port, PWR_LED1_Pin, 1);

		break;
	case P0:
		HAL_GPIO_WritePin(PWR_LED4_GPIO_Port, PWR_LED4_Pin, 0);
		HAL_GPIO_WritePin(PWR_LED3_GPIO_Port, PWR_LED3_Pin, 0);
		HAL_GPIO_WritePin(PWR_LED2_GPIO_Port, PWR_LED2_Pin, 0);
		HAL_GPIO_WritePin(PWR_LED1_GPIO_Port, PWR_LED1_Pin, 0);

		break;

	}
}
