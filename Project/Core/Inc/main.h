/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f1xx_hal.h"

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
#define OpenStepMotor_IN1_Pin GPIO_PIN_2
#define OpenStepMotor_IN1_GPIO_Port GPIOA
#define OpenStepMotor_IN2_Pin GPIO_PIN_3
#define OpenStepMotor_IN2_GPIO_Port GPIOA
#define OpenStepMotor_IN3_Pin GPIO_PIN_4
#define OpenStepMotor_IN3_GPIO_Port GPIOA
#define OpenStepMotor_IN4_Pin GPIO_PIN_5
#define OpenStepMotor_IN4_GPIO_Port GPIOA
#define CloseStepMotor_IN1_Pin GPIO_PIN_6
#define CloseStepMotor_IN1_GPIO_Port GPIOA
#define CloseStepMotor_IN2_Pin GPIO_PIN_7
#define CloseStepMotor_IN2_GPIO_Port GPIOA
#define CloseStepMotor_IN3_Pin GPIO_PIN_0
#define CloseStepMotor_IN3_GPIO_Port GPIOB
#define CloseStepMotor_IN4_Pin GPIO_PIN_1
#define CloseStepMotor_IN4_GPIO_Port GPIOB
#define Sensor1_GND_Pin GPIO_PIN_10
#define Sensor1_GND_GPIO_Port GPIOB
#define Sensor2_GND_Pin GPIO_PIN_11
#define Sensor2_GND_GPIO_Port GPIOB
#define Key_GND_Pin GPIO_PIN_12
#define Key_GND_GPIO_Port GPIOB
#define Key_1_Pin GPIO_PIN_13
#define Key_1_GPIO_Port GPIOB
#define Key_2_Pin GPIO_PIN_14
#define Key_2_GPIO_Port GPIOB
#define Key_3_Pin GPIO_PIN_15
#define Key_3_GPIO_Port GPIOB
#define Key_4_Pin GPIO_PIN_8
#define Key_4_GPIO_Port GPIOA
#define Sensor1_VCC_Pin GPIO_PIN_11
#define Sensor1_VCC_GPIO_Port GPIOA
#define Sensor2_VCC_Pin GPIO_PIN_12
#define Sensor2_VCC_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
