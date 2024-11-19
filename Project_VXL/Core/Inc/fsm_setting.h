/*
 * fsm_setting.h
 *
 *  Created on: Nov 19, 2024
 *      Author: ADMIN
 */

#ifndef INC_FSM_SETTING_H_
#define INC_FSM_SETTING_H_

#include <main.h>
#include <button.h>
#include <software_timer.h>
//#include <7SegLED.h>
#include <global_var.h>

#define INIT 0
#define GREEN_RED 1
#define YELLOW_RED 2
#define RED_GREEN 3
#define RED_YELLOW 4

#define EDIT_RED 11
#define EDIT_YELLOW 12
#define EDIT_GREEN 13


void changeMode();
void fsm_config();

#endif /* INC_FSM_SETTING_H_ */
