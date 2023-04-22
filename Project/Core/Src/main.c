/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "rtc.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "oled.h"
#include "stepmotor.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{
	/* USER CODE BEGIN 1 */
	RTC_DateTypeDef sdatestructure;
	RTC_TimeTypeDef stimestructure;
	uint32_t indoorADCValue = 0;
	uint32_t outdoorADCValue = 0;
	uint8_t x = 0;
	uint8_t y = 0;
	uint16_t indoorLimitHighValue = 1200;
	uint16_t indoorLimitLowValue = 800;
	uint16_t outdoorLimitHighValue = 1200;
	uint16_t outdoorLimitLowValue = 800;
	uint8_t i = 0;
	uint8_t j = 0;
	uint8_t k = 0;
	/* USER CODE END 1 */

	/* MCU Configuration--------------------------------------------------------*/

	/* Reset of all peripherals, Initializes the Flash interface and the Systick. */
	HAL_Init();

	/* USER CODE BEGIN Init */

	/* USER CODE END Init */

	/* Configure the system clock */
	SystemClock_Config();

	/* USER CODE BEGIN SysInit */

	/* USER CODE END SysInit */

	/* Initialize all configured peripherals */
	MX_GPIO_Init();
	MX_ADC1_Init();
	MX_RTC_Init();
	MX_USART1_UART_Init();
	MX_I2C1_Init();
	MX_ADC2_Init();
	/* USER CODE BEGIN 2 */
	HAL_ADC_Start(&hadc1);
	OLED_Init();
	OLED_Clear();
	OLED_ShowChinese(x + 16 + 16 * 0, y + 2 * 0, 0);
	OLED_ShowChinese(x + 16 + 16 * 1, y + 2 * 0, 1);
	OLED_ShowChinese(x + 16 + 16 * 2, y + 2 * 0, 2);
	OLED_ShowChinese(x + 16 + 16 * 3, y + 2 * 0, 3);
	OLED_ShowChinese(x + 16 + 16 * 4, y + 2 * 0, 4);
	OLED_ShowChinese(x + 16 + 16 * 5, y + 2 * 0, 5);
	OLED_ShowChinese(x + 16 * 0, y + 2 * 1, 6);
	OLED_ShowChinese(x + 16 * 1, y + 2 * 1, 7);
	OLED_ShowChar(x + 16 * 2 + 8 * 0, y + 2 * 1, ':', 16);
	OLED_ShowChinese(x + 16 * 0, y + 2 * 2, 8);
	OLED_ShowChinese(x + 16 * 1, y + 2 * 2, 9);
	OLED_ShowChar(x + 16 * 2 + 8 * 0, y + 2 * 2, ':', 16);
	OLED_ShowChinese(x + 16 * 0, y + 2 * 3, 10);
	OLED_ShowChinese(x + 16 * 1, y + 2 * 3, 11);
	OLED_ShowChar(x + 16 * 2 + 8 * 0, y + 2 * 3, ':', 16);
	/* USER CODE END 2 */

	/* Infinite loop */
	/* USER CODE BEGIN WHILE */
	while (1)
	{
		HAL_ADC_Start(&hadc1);
		HAL_ADC_PollForConversion(&hadc1, 50);
		indoorADCValue = HAL_ADC_GetValue(&hadc1);

		HAL_ADC_Start(&hadc2);
		HAL_ADC_PollForConversion(&hadc2, 50);
		outdoorADCValue = HAL_ADC_GetValue(&hadc2);

		HAL_RTC_GetTime(&hrtc, &stimestructure, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &sdatestructure, RTC_FORMAT_BIN);

		OLED_ShowNum(x + 16 * 2 + 8 * 1, y + 2 * 1, indoorADCValue, 5, 16);
		OLED_ShowChar(x + 16 * 2 + 8 * 7, y + 2 * 1, 'L', 16);
		OLED_ShowChar(x + 16 * 2 + 8 * 8, y + 2 * 1, 'x', 16);
		OLED_ShowNum(x + 16 * 2 + 8 * 1, y + 2 * 2, outdoorADCValue, 5, 16);
		OLED_ShowChar(x + 16 * 2 + 8 * 7, y + 2 * 2, 'L', 16);
		OLED_ShowChar(x + 16 * 2 + 8 * 8, y + 2 * 2, 'x', 16);

		if (HAL_GPIO_ReadPin(Key_1_GPIO_Port, Key_1_Pin) == GPIO_PIN_RESET)
		{
			HAL_Delay(50);
			i += 1;
		}
		switch (i % 3)
		{
		case 0:
			OLED_ShowChar(x + 16 * 2 + 8 * 1, y + 2 * 3, 'T', 16);
			OLED_ShowChar(x + 16 * 2 + 8 * 2, y + 2 * 3, 'i', 16);
			OLED_ShowChar(x + 16 * 2 + 8 * 3, y + 2 * 3, 'm', 16);
			OLED_ShowChar(x + 16 * 2 + 8 * 4, y + 2 * 3, 'e', 16);
			j = 3;
			break;
		case 1:
			OLED_ShowChar(x + 16 * 2 + 8 * 1, y + 2 * 3, 'A', 16);
			OLED_ShowChar(x + 16 * 2 + 8 * 2, y + 2 * 3, 'u', 16);
			OLED_ShowChar(x + 16 * 2 + 8 * 3, y + 2 * 3, 't', 16);
			OLED_ShowChar(x + 16 * 2 + 8 * 4, y + 2 * 3, 'o', 16);
			j = 1;
			break;
		case 2:
			OLED_ShowChar(x + 16 * 2 + 8 * 1, y + 2 * 3, 'H', 16);
			OLED_ShowChar(x + 16 * 2 + 8 * 2, y + 2 * 3, 'a', 16);
			OLED_ShowChar(x + 16 * 2 + 8 * 3, y + 2 * 3, 'n', 16);
			OLED_ShowChar(x + 16 * 2 + 8 * 4, y + 2 * 3, 'd', 16);
			j = 2;
			break;
		default:
			OLED_ShowChar(x + 16 * 2 + 8 * 1, y + 2 * 3, 'A', 16);
			OLED_ShowChar(x + 16 * 2 + 8 * 2, y + 2 * 3, 'u', 16);
			OLED_ShowChar(x + 16 * 2 + 8 * 3, y + 2 * 3, 't', 16);
			OLED_ShowChar(x + 16 * 2 + 8 * 4, y + 2 * 3, 'o', 16);
			j = 0;
			break;
		}
		switch (j)
		{
		case 0:

			break;
		case 1:
			break;
		case 2:
			if (HAL_GPIO_ReadPin(Key_2_GPIO_Port, Key_2_Pin) == GPIO_PIN_RESET)
			{
				HAL_Delay(50);
				OpenStepMotor_Start(2 * 3.14, 0);
				OpenStepMotor_Stop();
			}
			else if (HAL_GPIO_ReadPin(Key_3_GPIO_Port, Key_3_Pin) == GPIO_PIN_RESET)
			{
				HAL_Delay(50);
				CloseStepMotor_Start(2 * 3.14, 0);
				CloseStepMotor_Stop();
			}
			break;
		default:

			break;
		}
		switch (k % 2)
		{
		case 0:
			OpenStepMotor_Start(2 * 3.14, 0);
			OpenStepMotor_Stop();
			break;
		case 1:
			CloseStepMotor_Start(2 * 3.14, 0);
			CloseStepMotor_Stop();
			break;
		default:
			OpenStepMotor_Stop();
			CloseStepMotor_Stop();
			break;
		}

		printf("-------------------------\n");
		printf("当前室内照度：%d Lx\n", indoorADCValue);
		printf("当前室外照度：%d Lx\n", outdoorADCValue);
		if (1)
		{
			printf("当前窗帘状态：打开！\n");
		}
		else if (2)
		{
			printf("当前窗帘状态：关闭！\n");
		}
		printf("-------------------------\n");

		HAL_Delay(1000);
		/* USER CODE END WHILE */

		/* USER CODE BEGIN 3 */
	}
	/* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
	RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

	/** Initializes the RCC Oscillators according to the specified parameters
	 * in the RCC_OscInitTypeDef structure.
	 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI | RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.LSIState = RCC_LSI_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	{
		Error_Handler();
	}

	/** Initializes the CPU, AHB and APB buses clocks
	 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
	{
		Error_Handler();
	}
	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC | RCC_PERIPHCLK_ADC;
	PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;
	PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
	if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
	{
		Error_Handler();
	}
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
	/* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1)
	{
	}
	/* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
	/* USER CODE BEGIN 6 */
	/* User can add his own implementation to report the file name and line number,
	   ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
	/* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
