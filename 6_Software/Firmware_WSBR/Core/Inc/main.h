/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PWR_LED3_Pin GPIO_PIN_13
#define PWR_LED3_GPIO_Port GPIOC
#define PWR_LED4_Pin GPIO_PIN_14
#define PWR_LED4_GPIO_Port GPIOC
#define OSC_IN_Pin GPIO_PIN_0
#define OSC_IN_GPIO_Port GPIOH
#define NC1_Pin GPIO_PIN_1
#define NC1_GPIO_Port GPIOH
#define BMS_BATMS_Pin GPIO_PIN_0
#define BMS_BATMS_GPIO_Port GPIOA
#define BMS_SD_Pin GPIO_PIN_1
#define BMS_SD_GPIO_Port GPIOA
#define BMS_CEN_Pin GPIO_PIN_2
#define BMS_CEN_GPIO_Port GPIOA
#define BMS_CHG_Pin GPIO_PIN_3
#define BMS_CHG_GPIO_Port GPIOA
#define NRF_NCS_Pin GPIO_PIN_4
#define NRF_NCS_GPIO_Port GPIOA
#define NRF_SCK_Pin GPIO_PIN_5
#define NRF_SCK_GPIO_Port GPIOA
#define NRF_MISO_Pin GPIO_PIN_6
#define NRF_MISO_GPIO_Port GPIOA
#define NRF_MOSI_Pin GPIO_PIN_7
#define NRF_MOSI_GPIO_Port GPIOA
#define NRF_IRQ_Pin GPIO_PIN_0
#define NRF_IRQ_GPIO_Port GPIOB
#define NRF_CE_Pin GPIO_PIN_1
#define NRF_CE_GPIO_Port GPIOB
#define BT_G_Pin GPIO_PIN_2
#define BT_G_GPIO_Port GPIOB
#define BT_Y_Pin GPIO_PIN_10
#define BT_Y_GPIO_Port GPIOB
#define BT_R_Pin GPIO_PIN_12
#define BT_R_GPIO_Port GPIOB
#define LED_R_Pin GPIO_PIN_13
#define LED_R_GPIO_Port GPIOB
#define LED_G_Pin GPIO_PIN_14
#define LED_G_GPIO_Port GPIOB
#define LED_B_Pin GPIO_PIN_15
#define LED_B_GPIO_Port GPIOB
#define OSC_MCO_Pin GPIO_PIN_8
#define OSC_MCO_GPIO_Port GPIOA
#define PWR_SW_Pin GPIO_PIN_9
#define PWR_SW_GPIO_Port GPIOA
#define PWR_EN_Pin GPIO_PIN_10
#define PWR_EN_GPIO_Port GPIOA
#define USB_N_Pin GPIO_PIN_11
#define USB_N_GPIO_Port GPIOA
#define USB_P_Pin GPIO_PIN_12
#define USB_P_GPIO_Port GPIOA
#define SW_DIO_Pin GPIO_PIN_13
#define SW_DIO_GPIO_Port GPIOA
#define SW_CLK_Pin GPIO_PIN_14
#define SW_CLK_GPIO_Port GPIOA
#define SW_O_Pin GPIO_PIN_3
#define SW_O_GPIO_Port GPIOB
#define ACC_IRQ2_Pin GPIO_PIN_4
#define ACC_IRQ2_GPIO_Port GPIOB
#define ACC_IRQ1_Pin GPIO_PIN_5
#define ACC_IRQ1_GPIO_Port GPIOB
#define ACC_SCL_Pin GPIO_PIN_6
#define ACC_SCL_GPIO_Port GPIOB
#define ACC_SDA_Pin GPIO_PIN_7
#define ACC_SDA_GPIO_Port GPIOB
#define PWR_LED1_Pin GPIO_PIN_8
#define PWR_LED1_GPIO_Port GPIOB
#define PWR_LED2_Pin GPIO_PIN_9
#define PWR_LED2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
