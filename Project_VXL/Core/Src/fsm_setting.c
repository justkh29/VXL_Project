/*
 * fsm_setting.c
 *
 *  Created on: Nov 19, 2024
 *      Author: ADMIN
 */

#include <fsm_setting.h>
int mode = 1;

void changeMode()
{
	mode++;
	if (mode >= 5)
	{
		mode = 1;
	}
	switch(mode)
	{
		case 1:
			status = 0;
			break;
		case 2:
			ledReset();
			status = 11;
			break;
		case 3:
			ledReset();
			status = 12;
			break;
		case 4:
			ledReset();
			status = 13;
			break;
	}
}

void fsm_config()
{
	if (isButton1Pressed() == 1)
	{
		lcd_clear_display();
		changeMode();
		button1_flag = 0;
		button1_long_pressed = 0;
	}
	if (isButton3LongPressed() == 1)
	{
		lcd_clear_display();
		ledReset();
		status = 5;
		button3_long_pressed = 0;
	}
}
