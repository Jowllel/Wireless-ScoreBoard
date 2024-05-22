/**
 ******************************************************************************
 * @file        usermain.c
 * @author      jschaller
 * @date        25.04.2024
 * @version     1.0
 * @brief       main, that only contains user written code.
 ******************************************************************************
 */


#include "usermain.h"


void usermain(void)
{
	HAL_Delay(100);

	HAL_GPIO_WritePin(PWR_LED1_GPIO_Port, PWR_LED1_Pin, 1);
	bms_enPwr(false);

	while(1)
	{

	}
}

