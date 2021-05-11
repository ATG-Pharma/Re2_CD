/*
 * Gui.c
 *
 *  Created on: May 10, 2021
 *      Author: ATGDa
 */
#include "Gui.h"


void drawButton(int16_t x0, int16_t y0, int16_t h, int16_t w, char text[])
{
	//draw rectangle
	ILI9341_drawFastHLine(x0, y0, w, TEXT_COLOR);
	ILI9341_drawFastVLine(x0, y0, h, TEXT_COLOR);
	ILI9341_drawFastHLine(x0, y0+h, w, TEXT_COLOR);
	ILI9341_drawFastVLine(x0+w, y0, h, TEXT_COLOR);
	//text
	ILI9341_printText(text, x0+10, y0+h/4, TEXT_COLOR, BACKGROUND_COLOR, TEXT_SIZE);

}

