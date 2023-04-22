#include "stepmotor.h"

void OpenStepMotor_Control(uint8_t direction)
{
	static uint8_t step = 0;
	if (direction == 1)
	{
		if (step == 0)
		{
			step = 8;
		}
		else
		{
			step--;
		}
	}
	switch (step)
	{
	case 0:
		OpenStepMotor_1_H;
		OpenStepMotor_2_L;
		OpenStepMotor_3_L;
		OpenStepMotor_4_L;
		break;
	case 1:
		OpenStepMotor_1_H;
		OpenStepMotor_2_H;
		OpenStepMotor_3_L;
		OpenStepMotor_4_L;
		break;
	case 2:
		OpenStepMotor_1_L;
		OpenStepMotor_2_H;
		OpenStepMotor_3_L;
		OpenStepMotor_4_L;
		break;
	case 3:
		OpenStepMotor_1_L;
		OpenStepMotor_2_H;
		OpenStepMotor_3_H;
		OpenStepMotor_4_L;
		break;
	case 4:
		OpenStepMotor_1_L;
		OpenStepMotor_2_L;
		OpenStepMotor_3_H;
		OpenStepMotor_4_L;
		break;
	case 5:
		OpenStepMotor_1_L;
		OpenStepMotor_2_L;
		OpenStepMotor_3_H;
		OpenStepMotor_4_H;
		break;
	case 6:
		OpenStepMotor_1_L;
		OpenStepMotor_2_L;
		OpenStepMotor_3_L;
		OpenStepMotor_4_H;
		break;
	case 7:
		OpenStepMotor_1_H;
		OpenStepMotor_2_L;
		OpenStepMotor_3_L;
		OpenStepMotor_4_H;
		break;
	default:
		break;
	}
	if (direction == 0)
	{
		step++;
		if (8 == step)
		{
			step = 0;
		}
	}
}

void OpenStepMotor_Start(uint16_t angle, uint8_t direction)
{
	int i = 0;
	int pulse = (int)((double)(angle / 5.625) * 64);
	for (i = 0; i < pulse; i++)
	{
		OpenStepMotor_Control(direction);
		HAL_Delay(1);
	}
}

void OpenStepMotor_Stop(void)
{
	OpenStepMotor_1_L;
	OpenStepMotor_2_L;
	OpenStepMotor_3_L;
	OpenStepMotor_4_L;
}

void CloseStepMotor_Control(uint8_t direction)
{
	static uint8_t step = 0;
	if (direction == 1)
	{
		if (step == 0)
		{
			step = 8;
		}
		else
		{
			step--;
		}
	}
	switch (step)
	{
	case 0:
		CloseStepMotor_1_H;
		CloseStepMotor_2_L;
		CloseStepMotor_3_L;
		CloseStepMotor_4_L;
		break;
	case 1:
		CloseStepMotor_1_H;
		CloseStepMotor_2_H;
		CloseStepMotor_3_L;
		CloseStepMotor_4_L;
		break;
	case 2:
		CloseStepMotor_1_L;
		CloseStepMotor_2_H;
		CloseStepMotor_3_L;
		CloseStepMotor_4_L;
		break;
	case 3:
		CloseStepMotor_1_L;
		CloseStepMotor_2_H;
		CloseStepMotor_3_H;
		CloseStepMotor_4_L;
		break;
	case 4:
		CloseStepMotor_1_L;
		CloseStepMotor_2_L;
		CloseStepMotor_3_H;
		CloseStepMotor_4_L;
		break;
	case 5:
		CloseStepMotor_1_L;
		CloseStepMotor_2_L;
		CloseStepMotor_3_H;
		CloseStepMotor_4_H;
		break;
	case 6:
		CloseStepMotor_1_L;
		CloseStepMotor_2_L;
		CloseStepMotor_3_L;
		CloseStepMotor_4_H;
		break;
	case 7:
		CloseStepMotor_1_H;
		CloseStepMotor_2_L;
		CloseStepMotor_3_L;
		CloseStepMotor_4_H;
		break;
	default:
		break;
	}
	if (direction == 0)
	{
		step++;
		if (8 == step)
		{
			step = 0;
		}
	}
}

void CloseStepMotor_Start(uint16_t angle, uint8_t direction)
{
	int i = 0;
	int pulse = (int)((double)(angle / 5.625) * 64);
	for (i = 0; i < pulse; i++)
	{
		CloseStepMotor_Control(direction);
		HAL_Delay(1);
	}
}

void CloseStepMotor_Stop(void)
{
	CloseStepMotor_1_L;
	CloseStepMotor_2_L;
	CloseStepMotor_3_L;
	CloseStepMotor_4_L;
}
