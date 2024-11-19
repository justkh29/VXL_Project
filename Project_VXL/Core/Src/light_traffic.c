/*
 * light_traffic.c
 *
 *  Created on: Nov 19, 2024
 *      Author: ADMIN
 */

#include "light_traffic.h"
// D3/D4: LEFT LED
// D5/D6: RIGHT LED
// D7/D8: TOP LED
// D9/D10: BOTTOM LED
void ledReset()
{
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin , RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
	HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, RESET);
	HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, RESET);
	HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, RESET);
}
void ledRed_Green()
{
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);

	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
	HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, SET);
	HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, RESET);
	HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, SET);

}

void ledRed_Yellow()
{
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);

	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
	HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, RESET);
	HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, SET);
	HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, RESET);
}

void ledGreen_Red()
{
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);

	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
	HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, SET);
	HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, SET);
	HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, SET);
}

void ledYellow_Red()
{
	HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);

	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
	HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, SET);
	HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, SET);
	HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, SET);
}
