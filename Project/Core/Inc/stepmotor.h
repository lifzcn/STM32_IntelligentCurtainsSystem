#ifndef __STEPMOTOR_H__
#define __STEPMOTOR_H__

#include "stm32f1xx_hal.h"
#include "main.h"

#define OpenStepMotor_1_H HAL_GPIO_WritePin(OpenStepMotor_IN1_GPIO_Port, OpenStepMotor_IN1_Pin, GPIO_PIN_SET)
#define OpenStepMotor_1_L HAL_GPIO_WritePin(OpenStepMotor_IN1_GPIO_Port, OpenStepMotor_IN1_Pin, GPIO_PIN_RESET)

#define OpenStepMotor_2_H HAL_GPIO_WritePin(OpenStepMotor_IN2_GPIO_Port, OpenStepMotor_IN2_Pin, GPIO_PIN_SET)
#define OpenStepMotor_2_L HAL_GPIO_WritePin(OpenStepMotor_IN2_GPIO_Port, OpenStepMotor_IN2_Pin, GPIO_PIN_RESET)

#define OpenStepMotor_3_H HAL_GPIO_WritePin(OpenStepMotor_IN3_GPIO_Port, OpenStepMotor_IN3_Pin, GPIO_PIN_SET)
#define OpenStepMotor_3_L HAL_GPIO_WritePin(OpenStepMotor_IN3_GPIO_Port, OpenStepMotor_IN3_Pin, GPIO_PIN_RESET)

#define OpenStepMotor_4_H HAL_GPIO_WritePin(OpenStepMotor_IN4_GPIO_Port, OpenStepMotor_IN4_Pin, GPIO_PIN_SET)
#define OpenStepMotor_4_L HAL_GPIO_WritePin(OpenStepMotor_IN4_GPIO_Port, OpenStepMotor_IN4_Pin, GPIO_PIN_RESET)

#define CloseStepMotor_1_H HAL_GPIO_WritePin(CloseStepMotor_IN1_GPIO_Port, CloseStepMotor_IN1_Pin, GPIO_PIN_SET)
#define CloseStepMotor_1_L HAL_GPIO_WritePin(CloseStepMotor_IN1_GPIO_Port, CloseStepMotor_IN1_Pin, GPIO_PIN_RESET)

#define CloseStepMotor_2_H HAL_GPIO_WritePin(CloseStepMotor_IN2_GPIO_Port, CloseStepMotor_IN2_Pin, GPIO_PIN_SET)
#define CloseStepMotor_2_L HAL_GPIO_WritePin(CloseStepMotor_IN2_GPIO_Port, CloseStepMotor_IN2_Pin, GPIO_PIN_RESET)

#define CloseStepMotor_3_H HAL_GPIO_WritePin(CloseStepMotor_IN3_GPIO_Port, CloseStepMotor_IN3_Pin, GPIO_PIN_SET)
#define CloseStepMotor_3_L HAL_GPIO_WritePin(CloseStepMotor_IN3_GPIO_Port, CloseStepMotor_IN3_Pin, GPIO_PIN_RESET)

#define CloseStepMotor_4_H HAL_GPIO_WritePin(CloseStepMotor_IN4_GPIO_Port, CloseStepMotor_IN4_Pin, GPIO_PIN_SET)
#define CloseStepMotor_4_L HAL_GPIO_WritePin(CloseStepMotor_IN4_GPIO_Port, CloseStepMotor_IN4_Pin, GPIO_PIN_RESET)

void OpenStepMotor_Control(uint8_t direction);
void OpenStepMotor_Start(uint16_t angle, uint8_t direction);
void OpenStepMotor_Stop(void);

void CloseStepMotor_Control(uint8_t direction);
void CloseStepMotor_Start(uint16_t angle, uint8_t direction);
void CloseStepMotor_Stop(void);

#endif
