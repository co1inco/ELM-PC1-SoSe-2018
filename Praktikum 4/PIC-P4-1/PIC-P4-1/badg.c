/*
 * badg.c
 *
 * Created: 23.05.2018 09:15:23
 *  Author: Colin
 */ 

#include "snakeLib.h"

#include <avr/io.h>

uint8_t posxB;
int16_t posyB;

uint8_t currentSpriteB = 0;

int8_t direction = 1;

uint8_t meinSchurke[4][SIZE][SIZE] =
{
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0 },
		{ 1, 1, 1, 0, 0, 0, 3, 3, 0, 0, 0 },
		{ 0, 0, 1, 5, 5, 5, 5, 5, 5, 0, 0 },
		{ 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 0 },
		{ 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 5 },
		{ 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0 },
		{ 1, 1, 1, 0, 0, 0, 3, 3, 0, 0, 0 },
		{ 0, 0, 1, 5, 5, 5, 5, 5, 5, 0, 0 },
		{ 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 0 },
		{ 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 5 },
		{ 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 }
	},
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0 },
		{ 1, 1, 1, 0, 0, 0, 3, 3, 0, 0, 0 },
		{ 0, 0, 1, 5, 5, 5, 5, 5, 5, 0, 0 },
		{ 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 0 },
		{ 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 5 },
		{ 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 }
	},
	{
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0 },
		{ 1, 1, 1, 0, 0, 0, 3, 3, 0, 0, 0 },
		{ 0, 0, 1, 5, 5, 5, 5, 5, 5, 0, 0 },
		{ 0, 0, 0, 0, 0, 5, 5, 5, 0, 5, 0 },
		{ 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 5 },
		{ 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 }
	}
};

void moveB(){
	drawSprite(posxB, posyB, 1, backgroundSprite);

	if (posyB > DISPHEIGHT-SIZE){
		direction = -1;
	} else if (posyB < 10) {
		direction = 1;
	}
	
	posyB = posyB + SIZE * direction;
	drawSprite(posxB, posyB, 2, meinSchurke[currentSpriteB]);
	
}

void initB(){
	posxB = 10;
	posyB = DISPHEIGHT/2;
}

void removeB(){
	drawSprite(posxB, posyB, 1, backgroundSprite);
}

void changeSpriteB(){
	if (currentSpriteB == 3)
	currentSpriteB = 0;
	else
	currentSpriteB += 1;
	
//	drawSprite(posxB, posyB, 1, backgroundSprite);
	drawSprite(posxB, posyB, 2, meinSchurke[currentSpriteB]);
}

uint8_t getyB(){
	return posyB;
}