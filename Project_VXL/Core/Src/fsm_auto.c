/*
 * fsm_auto.c
 *
 *  Created on: Nov 19, 2024
 *      Author: ADMIN
 */

#include "fsm_auto.h"

void fsm_auto_run()
{
	switch(status)
	{
		case INIT:
			ledReset();
			status = 1;
			setTimer(0, 1000);
			count = duration_G;
			break;
		case GREEN_RED:
			ledGreen_Red();
			if (timer_flag[0] == 1)
			{
				lcd_clear_display();
				lcd_display(1, 0, count);
				lcd_display(2, 0, count + duration_Y);
				count--;
				if (count <= 0)
				{
					ledReset();
					status = 2;
					count = duration_Y;
				}
				timer_flag[0] = 0;
				setTimer(0, 1000);
			}
			if (isButton2Pressed() == 1)
			{
				button2_flag = 0;
			}
			break;
		case YELLOW_RED:
			ledYellow_Red();
			if (timer_flag[0] == 1)
			{
				lcd_clear_display();
				lcd_display(1, 0, count);
				lcd_display(2, 0, count);
				count--;
				if (count <= 0)
				{
					ledReset();
					status = 3;
					count = duration_R - duration_Y;
				}

				timer_flag[0] = 0;
				setTimer(0, 1000);
			}
			if (isButton2Pressed() == 1)
			{
				button2_flag = 0;
			}
			break;
		case RED_GREEN:
			ledRed_Green();
			if (timer_flag[0] == 1)
			{
				lcd_clear_display();
				lcd_display(1, 0, count + duration_Y);
				lcd_display(2, 0, count);
				count--;
				if (count <= 0)
				{
					ledReset();
					status = 4;
					count = duration_Y;
				}
				timer_flag[0] = 0;
				setTimer(0, 1000);
			}
			if (isButton2Pressed() == 1)
			{
				button2_flag = 0;
			}
			break;
		case RED_YELLOW:
			ledRed_Yellow();
			if (timer_flag[0] == 1)
			{
				lcd_clear_display();
				lcd_display(1, 0, count);
				lcd_display(2, 0, count);
				count--;
				if (count <= 0)
				{
					ledReset();
					status = 1;
					count = duration_G;
				}

				timer_flag[0] = 0;
				setTimer(0, 1000);
			}
			if (isButton2Pressed() == 1)
			{
				button2_flag = 0;
			}
			break;
	}
}
