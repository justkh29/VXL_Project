/*
 * fsm_edit.c
 *
 *  Created on: Nov 19, 2024
 *      Author: ADMIN
 */

#include <fsm_edit.h>

void fsm_edit()
{
	switch (status)
	{
		case EDIT_RED:
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);

			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
			HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, SET);
			HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, SET);
			HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, SET);
			if (isButton2Pressed() == 1)
			{
				duration_ADD++;
				if (duration_ADD + duration_R > 99)
				{
					lcd_clear_display();
					duration_ADD = 0;
				}
				button2_flag = 0;
			}
			if (isButton2LongPressed() == 1)
			{
				duration_ADD--;
				if (duration_R + duration_ADD <= 0 || duration_R + duration_ADD - 1 < duration_Y)
				{
					lcd_clear_display();
					duration_ADD = 0;
				}
				button2_long_pressed = 0;
			}

			lcd_goto_XY(1, 0);
			lcd_send_string("Red LED Mode");
			lcd_goto_XY(2, 0);
			lcd_send_string("Duration: ");
			lcd_display(2, 10, duration_R + duration_ADD);


			if (isButton3Pressed() == 1)
			{
				duration_R += duration_ADD;
				duration_ADD = 0;
				button3_flag = 0;
			}
			if (isButton1Pressed() == 1)
			{
				duration_ADD = 0;
			}

			break;
		case EDIT_YELLOW:
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, RESET);
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, SET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, RESET);
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, SET);

			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, RESET);
			HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, SET);
			HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, RESET);
			HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, SET);
			if (isButton2Pressed() == 1)
			{
				duration_ADD++;
				if ((duration_Y + duration_ADD > duration_R - 1) || (duration_Y + duration_ADD > duration_G - 2))
				{
					lcd_clear_display();
					duration_ADD = 0;
				}
				button2_flag = 0;
			}
			if (isButton2LongPressed() == 1)
			{
				duration_ADD--;
				if (duration_Y + duration_ADD <= 0)
				{
					lcd_clear_display();
					duration_ADD = 0;
				}
				button2_long_pressed = 0;
			}
			lcd_goto_XY(1, 0);
			lcd_send_string("Yellow LED Mode");
			lcd_goto_XY(2, 0);
			lcd_send_string("Duration: ");
			lcd_display(2, 10, duration_Y + duration_ADD);
			if (isButton3Pressed() == 1)
			{
				duration_Y += duration_ADD;
				duration_ADD = 0;
				button3_flag = 0;
			}
			if (isButton1Pressed() == 1)
			{
				duration_ADD = 0;
			}
			break;
		case EDIT_GREEN:
			HAL_GPIO_WritePin(D3_GPIO_Port, D3_Pin, SET);
			HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, RESET);
			HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, SET);
			HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, RESET);

			HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, SET);
			HAL_GPIO_WritePin(D8_GPIO_Port, D8_Pin, RESET);
			HAL_GPIO_WritePin(D9_GPIO_Port, D9_Pin, SET);
			HAL_GPIO_WritePin(D10_GPIO_Port, D10_Pin, RESET);
			if (isButton2Pressed() == 1)
			{
				duration_ADD++;
				if (duration_G + duration_ADD > 99)
				{
					lcd_clear_display();
					duration_ADD = 0;
				}
				button2_flag = 0;
			}
			if (isButton2LongPressed() == 1)
			{
				duration_ADD--;
				if (duration_G + duration_ADD <= 0 || duration_G + duration_ADD - 2 < duration_Y)
				{
					lcd_clear_display();
					duration_ADD = 0;
				}
				button2_long_pressed = 0;
			}
			lcd_goto_XY(1, 0);
			lcd_send_string("Green LED Mode");
			lcd_goto_XY(2, 0);
			lcd_send_string("Duration: ");
			lcd_display(2, 10, duration_G + duration_ADD);
			if (isButton3Pressed() == 1)
			{
				duration_G += duration_ADD;
				duration_ADD = 0;
				button3_flag = 0;
			}
			if (isButton1Pressed() == 1)
			{
				duration_ADD = 0;
			}
			break;
		case MAN_GREEN_RED:
			ledGreen_Red();
			lcd_goto_XY(1, 0);
			lcd_send_string("Green");
			lcd_goto_XY(2, 0);
			lcd_send_string("Red");
			if (isButton3Pressed() == 1)
			{
				lcd_clear_display();
				ledReset();
				status = 6;
				button3_flag = 0;
			}

			if (isButton2Pressed() == 1)
			{
				lcd_clear_display();
				status = 0;
				mode = 1;
				button2_flag = 0;
			}
			break;
		case MAN_YELLOW_RED:
			ledYellow_Red();
			lcd_goto_XY(1, 0);
			lcd_send_string("Yellow");
			lcd_goto_XY(2, 0);
			lcd_send_string("Red");
			if (isButton3Pressed() == 1)
			{
				ledReset();
				status = 7;
				button3_flag = 0;
				lcd_clear_display();
			}

			if (isButton2Pressed() == 1)
			{
				lcd_clear_display();
				status = 0;
				mode = 1;
				button2_flag = 0;
			}
			break;
		case MAN_RED_GREEN:
			ledRed_Green();
			lcd_goto_XY(1, 0);
			lcd_send_string("Red");
			lcd_goto_XY(2, 0);
			lcd_send_string("Green");
			if (isButton3Pressed() == 1)
			{
				lcd_clear_display();
				ledReset();
				status = 8;
				button3_flag = 0;
			}

			if (isButton2Pressed() == 1)
			{
				lcd_clear_display();
				status = 0;
				mode = 1;
				button2_flag = 0;
			}
			break;
		case MAN_RED_YELLOW:
			ledRed_Yellow();
			lcd_goto_XY(1, 0);
			lcd_send_string("Red");
			lcd_goto_XY(2, 0);
			lcd_send_string("Yellow");
			if (isButton3Pressed() == 1)
			{
				lcd_clear_display();
				ledReset();
				status = 5;
				button3_flag = 0;
			}

			if (isButton2Pressed() == 1)
			{
				lcd_clear_display();
				status = 0;
				mode = 1;
				button2_flag = 0;
			}
			break;
	}
	if ((duration_R == 99) && (duration_G == 99) && (duration_Y == 97))
	{
		duration_R = duration_R_default;
		duration_Y = duration_Y_default;
		duration_G = duration_G_default;
	}
}

