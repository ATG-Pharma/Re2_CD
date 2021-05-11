/*
 * Gui.h
 *
 *  Created on: May 10, 2021
 *      Author: ATGDa
 */

#ifndef INC_GUI_H_
#define INC_GUI_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "MY_ILI9341.h"
#include "TSC2046.h"

#define BUTTON_HEIGHT 40
#define TEXT_SIZE 2
#define BACKGROUND_COLOR COLOR_BLACK
#define TEXT_COLOR COLOR_WHITE

typedef struct {
	int16_t x;
	int16_t y;
	int16_t h;
	int16_t w;
	char text[];
}Gui_Button_t;

void drawButton(int16_t x0, int16_t y0, int16_t h, int16_t w, char text[]);

#endif /* INC_GUI_H_ */
