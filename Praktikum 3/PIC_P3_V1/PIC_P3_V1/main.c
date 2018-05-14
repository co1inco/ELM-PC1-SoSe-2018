/*
 * PIC_P3_V1.c
 *
 * Created: 14.05.2018 21:14:17
 * Author : Colin
 */ 

#include <avr/io.h>

#include "s65_stk600.h"
#include "coLib1.h"

#define  F_CPU  8000000
#include <util/delay.h>

/*
int headSpriteX[11][10] = {
	{ 0, 0, 1, 0, 1, 1, 1, 1, 0, 0},
	{ 0, 0, 1, 1, 0, 1, 1, 1, 0, 0},
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{ 0, 1, 0, 0, 1, 1, 0, 0, 1, 0},
	{ 0, 1, 0, 1, 1, 1, 1, 0, 1, 0},
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{ 0, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{ 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
	{ 0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
	{ 0, 0, 0, 0, 1, 1, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};
*/

int main(void)
{

	
	lcd_Init();
	lcd_ClearScreen(0xffff);
	
	uint8_t sizeX = 10;
	uint8_t sizeY = 11;
	
	uint16_t posX;
	uint16_t posY;
	
	uint8_t offX = 5;
	uint8_t offY = 10;
	
	for (posY=0; posY<sizeY; posY++){
		for (posX=0; posX<sizeX; posX++){
			if (headSpriteX[posY][posX] == 1)
				lcd_DrawPixel(offX+posX, offY+posY, LCD_COLOR_WHITE);
		}
	}
	
	/*
	lcd_ClearScreen(0xffff);
	uint8_t d = 1;
	while (1){
		drawSprite(offX, offY, d, appleSprite);
		if (d==4)
			d = 1;
		else
			d = d+1;
		_delay_ms(200);
	}
	*/
}

