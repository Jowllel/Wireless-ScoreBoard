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


extern I2C_HandleTypeDef hi2c1;
ADXL_InitTypeDef hadxl1;


void usermain(void)
{
	bms_enPwr(true);

	uint8_t batPercent;
	uint8_t buttonState = 0;
	bool powerMode = false;
	bool shortPressed = false;
	uint32_t lastShortPressed;

	float out[3];

	hadxl1.AutoSleep = 0;
	hadxl1.IntMode = 0;
	hadxl1.Justify = 0;
	hadxl1.LPMode = 0;
	hadxl1.LinkMode = 0;
	hadxl1.Range = 0;
	hadxl1.Rate = 10;
	hadxl1.Resolution = 0;
	hadxl1.SPIMode = 0;

	ADXL_Init(&hadxl1);

	ADXL_Measure(ON);


	while(1)
	{
		batPercent = bms_getBatPercent();

		if(bms_getChargingState())
		{
			if(batPercent < 25)		 setBatLed(P0_CHARGING);
			else if(batPercent < 50) setBatLed(P25_CHARGING);
			else if(batPercent < 75) setBatLed(P50_CHARGING);
			else if(batPercent < 95) setBatLed(P75_CHARGING);
			else				     setBatLed(P100_CHARGING);

			powerMode = false;
		}
		else
		{
			if(batPercent < 5)			setBatLed(P0_SOURCE);
			else if(batPercent < 25)	setBatLed(P25_SOURCE);
			else if(batPercent < 50)	setBatLed(P50_SOURCE);
			else if(batPercent < 75)	setBatLed(P75_SOURCE);
			else						setBatLed(P100_SOURCE);


			if(!powerMode)
			{
				if((HAL_GetTick() >= 2000)) bms_enPwr(false);

				if((!HAL_GPIO_ReadPin(PWR_SW_GPIO_Port, PWR_SW_Pin)) && (buttonState == 0)) buttonState = 1;
				if((HAL_GPIO_ReadPin(PWR_SW_GPIO_Port, PWR_SW_Pin)) && (buttonState == 1)) buttonState = 2;
				if((!HAL_GPIO_ReadPin(PWR_SW_GPIO_Port, PWR_SW_Pin)) && (buttonState >= 2)) bms_enPwr(false);

				if(buttonState == 2)
				{
					setBatLed(P25_SOURCE);
					HAL_Delay(200);
					buttonState = 3;
				}
				else if(buttonState == 3)
				{

					setBatLed(P50_SOURCE);
					HAL_Delay(200);
					buttonState = 4;
				}
				else if(buttonState == 4)
				{
					setBatLed(P75_SOURCE);
					HAL_Delay(200);
					buttonState = 5;
				}
				else if(buttonState == 5)
				{
					setBatLed(P100_SOURCE);
					HAL_Delay(200);
					powerMode = true;
					buttonState = 6;
					bms_enPwr(true);
				}
			}
			else
			{
				if(!shortPressed)
				{
					if((!HAL_GPIO_ReadPin(PWR_SW_GPIO_Port, PWR_SW_Pin)) && (buttonState == 6)) buttonState = 1;
					if((HAL_GPIO_ReadPin(PWR_SW_GPIO_Port, PWR_SW_Pin)) && (buttonState == 1))
					{
						setBatLed(P0);
						buttonState = 6;
						shortPressed = true;
						lastShortPressed = HAL_GetTick();
					}
				}
				else
				{
					if(((HAL_GetTick() - lastShortPressed) >= 2000) && (buttonState == 1)) shortPressed = false;

					setBatLed(P0);
					if((!HAL_GPIO_ReadPin(PWR_SW_GPIO_Port, PWR_SW_Pin)) && (buttonState == 6)) buttonState = 1;
					if((HAL_GPIO_ReadPin(PWR_SW_GPIO_Port, PWR_SW_Pin)) && (buttonState == 1)) buttonState = 2;
					if((!HAL_GPIO_ReadPin(PWR_SW_GPIO_Port, PWR_SW_Pin)) && (buttonState >= 2)) buttonState = 1;

					if(buttonState == 2)
					{
						setBatLed(P100_SOURCE);
						HAL_Delay(200);
						buttonState = 3;
					}
					else if(buttonState == 3)
					{

						setBatLed(P75_SOURCE);
						HAL_Delay(200);
						buttonState = 4;
					}
					else if(buttonState == 4)
					{
						setBatLed(P50_SOURCE);
						HAL_Delay(200);
						buttonState = 5;
					}
					else if(buttonState == 5)
					{
						setBatLed(P25_SOURCE);
						HAL_Delay(200);
						setBatLed(P0_SOURCE);
						bms_enPwr(false);
						buttonState = 6;
					}
				}

				//MAIN LOOOP


//				ADXL_enableSingleTap(INT1, X_axes | Y_axes | Z_axes, 10, 10);
//				ADXL_enableDoubleTap(INT1, X_axes | Y_axes | Z_axes, 10, 10, 100, 100);

				ADXL_getAccel(out, OUTPUT_FLOAT);

				asm("nop");


			}
		}
		HAL_Delay(10);
	}
}

