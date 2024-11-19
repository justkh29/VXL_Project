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
			if (isButton2Pressed() == 1 || isButton2LongPressed() == 1)
			{
				duration_ADD++;
				button2_flag = 0;
				button2_long_pressed = 0;
			}
			if (isButton3Pressed() == 1)
			{
				duration_R += duration_ADD;
				if (duration_R > 99)
				{
					duration_R = 1;
				}
				duration_ADD = 0;
				button3_flag = 0;
			}
			if (isButton1Pressed() == 1)
			{
				duration_ADD = 0;
			}
			break;
		case EDIT_YELLOW:
			if (isButton2Pressed() == 1 || isButton2LongPressed() == 1)
			{
				duration_ADD++;

				button2_flag = 0;
				button2_long_pressed = 0;
			}
			if (isButton3Pressed() == 1)
			{
				duration_Y += duration_ADD;
				if (duration_Y > 99)
				{
					duration_Y = 1;
				}
				duration_ADD = 0;
				button3_flag = 0;
			}
			if (isButton1Pressed() == 1)
			{
				duration_ADD = 0;
			}
			break;
		case EDIT_GREEN:
			if (isButton2Pressed() == 1 || isButton2LongPressed() == 1)
			{
				duration_ADD++;
				button2_flag = 0;
				button2_long_pressed = 0;
			}
			if (isButton3Pressed() == 1)
			{
				duration_G += duration_ADD;
				if (duration_G > 99)
				{
					duration_G = 1;
				}
				duration_ADD = 0;
				button3_flag = 0;
			}
			if (isButton1Pressed() == 1)
			{
				duration_ADD = 0;
			}
			break;
	}
}

