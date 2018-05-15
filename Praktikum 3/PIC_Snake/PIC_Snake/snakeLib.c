/*
 * CFile1.c
 *
 * Created: 06.05.2018 17:13:46
 *  Author: Colin
 */ 

#include <avr/io.h>


#include "snakeLib.h"
#include "s65_stk600.h"


#define RIGHT (1)
#define UP (2)
#define LEFT (3)
#define DOWN (4)


color white = { 0xFF, 0xFF, 0xFF};
color black = {  0x0,  0x0,  0x0};
color blue  = { 0xFF,  0x0,  0x0};
color red   = {  0x0,  0x0, 0xFF};

color snakeGreen = { 13, 215, 13};
color snakeStripes = { 00, 36, 05};
color appleRed		= { 0x10, 0x10, 0xf4};
color appleRed2	= { 0x52, 0x2c, 0xf8};
color appleBrown	= { 0x02, 0x02, 0x79};


uint8_t headSprite[10][10] = {
	{ 0, 0, 2, 3, 2, 2, 2, 2, 0, 0},
	{ 0, 0, 2, 2, 3, 2, 2, 2, 0, 0},
	{ 0, 2, 2, 2, 2, 2, 2, 2, 2, 0},
	{ 0, 2, 1, 1, 2, 2, 1, 1, 2, 0},
	{ 0, 2, 1, 4, 2, 2, 4, 1, 2, 0},
	{ 0, 2, 2, 2, 2, 2, 2, 2, 2, 0},
	{ 0, 2, 2, 2, 2, 2, 2, 2, 2, 0},
	{ 0, 0, 2, 4, 2, 2, 4, 2, 0, 0},
	{ 0, 0, 0, 2, 2, 2, 2, 0, 0, 0},
	{ 0, 0, 0, 0, 2, 2, 0, 0, 0, 0},
};

uint8_t partSprite[10][10] = {
	{ 0, 0, 2, 3, 2, 2, 2, 2, 0, 0},
	{ 0, 0, 2, 2, 3, 2, 2, 2, 0, 0},
	{ 0, 0, 2, 2, 2, 3, 2, 2, 0, 0},
	{ 0, 0, 2, 2, 2, 2, 3, 2, 0, 0},
	{ 0, 0, 2, 2, 2, 2, 2, 2, 0, 0},
	{ 0, 0, 2, 3, 2, 2, 2, 2, 0, 0},
	{ 0, 0, 2, 2, 3, 2, 2, 2, 0, 0},
	{ 0, 0, 2, 2, 2, 3, 2, 2, 0, 0},
	{ 0, 0, 2, 2, 2, 2, 3, 2, 0, 0},
	{ 0, 0, 2, 2, 2, 2, 2, 2, 0, 0},
};

uint8_t taleSprite[10][10] = {
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 2, 2, 0, 0, 0, 0},
	{ 0, 0, 0, 2, 1, 2, 2, 0, 0, 0},
	{ 0, 0, 0, 2, 2, 3, 2, 0, 0, 0},
	{ 0, 0, 2, 3, 2, 2, 3, 2, 0, 0},
	{ 0, 0, 2, 2, 3, 2, 2, 2, 0, 0},
	{ 0, 0, 2, 2, 2, 3, 2, 2, 0, 0},
	{ 0, 0, 2, 2, 2, 2, 3, 2, 0, 0},
	{ 0, 0, 2, 2, 2, 2, 2, 2, 0, 0},
};

uint8_t turnSprite[10][10] = {
	{ 0, 0, 2, 3, 2, 2, 2, 2, 0, 0},
	{ 0, 0, 2, 2, 3, 2, 2, 2, 0, 0},
	{ 2, 2, 2, 2, 2, 3, 2, 2, 0, 0},
	{ 2, 2, 2, 2, 3, 2, 3, 2, 0, 0},
	{ 2, 2, 2, 3, 2, 2, 3, 2, 0, 0},
	{ 2, 2, 3, 2, 2, 3, 2, 2, 0, 0},
	{ 2, 3, 2, 2, 3, 2, 2, 0, 0, 0},
	{ 3, 2, 2, 2, 2, 2, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

uint8_t appleSprite[10][10] = {
	{ 0 ,0, 2, 2, 0, 7, 7, 0, 0, 0},
	{ 0, 0, 0, 0, 2, 7, 0, 0, 0, 0},
	{ 0, 5, 5, 5, 7, 0, 5, 5, 5, 0},
	{ 0, 5, 5, 5, 7, 5, 5, 5, 5, 5},
	{ 5, 5, 5, 5, 5, 5, 6, 6, 5, 5},
	{ 5, 5, 5, 5, 5, 5, 6, 6, 5, 5},
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 0},
	{ 0, 5, 5, 5, 5, 5, 5, 5, 5, 0},
	{ 0, 0, 5, 5, 0, 0, 5, 5, 0, 0},
};



long map(long value, long fromLow, long fromHigh, long toLow, long toHigh){
	long fromDif = fromHigh - fromLow;
	long toDif   = toHigh - toLow;
	
	value = value - fromLow;
	
	long fVal = (toDif/100.0 ) * ((100.0/fromDif)*value);
	
	return toLow+fVal;
}

uint16_t value_to_led(uint16_t lower, uint16_t upper, uint16_t value){
	if (value < lower){	
		return 0x00;
	} else if (value > upper) {		
		return 0xff;
	} else {
		uint16_t led = 0x01 << map(value, lower, upper, 0, 8);
		return led;
	}
}

uint16_t value_to_celsius(uint16_t value){
	uint16_t kel = map(value, 0, 1023, 0, 500); // 500 => 5V
	return kel - 273; // 273,15
}

// 1111 1000 0000 0000 RED
// 0000 0000 0001 1111 BLUE
// 0000 0111 1110 0000 GREEN

int col2lcd(uint8_t blue, uint8_t green, uint8_t red){
	int colors = 0x0000;
	
	colors = colors | (map(red,   0, 255, 0, 31) << 11);
	colors = colors | (map(green, 0, 255, 0, 63) << 6);
	colors = colors |  map(blue,  0, 255, 0, 31);
	
	return colors;
}

int color2lcd(color col){
	int colors = 0x0000;
	
	colors = colors | (map(col.red,   0, 255, 0, 31) << 11);
	colors = colors | (map(col.green, 0, 255, 0, 63) << 6);
	colors = colors |  map(col.blue,  0, 255, 0, 31);
	
	return colors;
}

void drawPixel_int2col(uint16_t oPosX, uint16_t oPosY, uint16_t posY, uint16_t posX,  uint16_t col){
	switch (col)
	{
		case 1:
			lcd_DrawPixel(oPosX+ posX, oPosY+posY, color2lcd(white));
//			drawPixel( fb, pos, posY, posX, white);
			break;
		case 2:
			lcd_DrawPixel(oPosX+ posX, oPosY+posY, color2lcd(snakeGreen));
			break;
		case 3:
			lcd_DrawPixel(oPosX+ posX, oPosY+posY, color2lcd(snakeStripes));
			break;
		case 4:
			lcd_DrawPixel(oPosX+ posX, oPosY+posY, color2lcd(black));
			break;
			
		case 5:
			lcd_DrawPixel(oPosX+ posX, oPosY+posY, color2lcd(appleRed));
			break;
		case 6:
			lcd_DrawPixel(oPosX+ posX, oPosY+posY, color2lcd(appleRed2));
			break;
		case 7:
			lcd_DrawPixel(oPosX+ posX, oPosY+posY, color2lcd(appleBrown));
			break;
		default:
			break;			
	}
}

void drawSprite(uint16_t posX, uint16_t posY, uint8_t direction, uint8_t sprite[10][10]){
	uint8_t spriteWidth = 10; //Y
	uint8_t spriteHeight = 10;  //X
	
	uint8_t spriteX;
	uint8_t spriteY;
	uint8_t dispHei;
	uint8_t dispWid;
	
	switch (direction) {
		
		case 1:		// Right
			for (spriteY=0 ; spriteY < spriteWidth; spriteY++){
				for (spriteX=0; spriteX < spriteHeight; spriteX++){
					drawPixel_int2col( posX, posY, spriteY, spriteX, sprite[spriteX][spriteY]);				
				}
			}
			break;
			
		case 2:		// Up
			for (spriteY=0; spriteY < spriteWidth; spriteY++){
				dispWid = spriteWidth-1;
				for (spriteX=0; spriteX < spriteHeight; spriteX++){
					drawPixel_int2col( posX, posY, spriteY, dispWid, sprite[spriteY][spriteX]);
					dispWid--;				
				}
			}
			break;
			
		case 3:		// Left
			dispHei = spriteHeight;
			for (spriteY=0; spriteY < spriteWidth; spriteY++){
				dispWid = spriteWidth;
				dispHei--;
				for (spriteX=0; spriteX < spriteHeight; spriteX++){
					drawPixel_int2col( posX, posY, dispHei, dispWid-1, sprite[spriteX][spriteY]);
					dispWid--;
				}
			}
			break;
			
		case 4:		// Down
			dispHei = spriteHeight-1;
			for (spriteY=0; spriteY < spriteWidth; spriteY++){
				dispWid = 0;
				for (spriteX=0; spriteX < spriteHeight; spriteX++){
					drawPixel_int2col( posX, posY, dispHei, dispWid, sprite[spriteY][spriteX]);
					dispWid++;
				}
				dispHei--;
			}
			break;
		
		default:
			break;
	}
}


void drawSpriteC(int posx, int posy, int direction, int type){
	if (type == 1 && direction){
		drawSprite(posx, posy, direction, headSprite);
	}
	if (type == 2 && direction <= 4){
		drawSprite(posx, posy, direction, partSprite);
	}
	if (type == 3){
		drawSprite(posx, posy, direction, taleSprite);
	}
	if (type == 4){
		if (direction > 4) direction = direction - 4;
		drawSprite(posx, posy, direction, turnSprite);
	}
	if (type == 5){
		drawSprite(posx, posy, 4, appleSprite);
	}
}


uint8_t hidKeysDown(){
	return ~PINA;
}

void hidInit(){
	DDRA = 0x00;
}

part* newPart(int posX, int posY, int d, int t){
	
	part *p = malloc(sizeof(part));
	p ->x = posX;
	p ->y = posY;
	p ->direction = d;
	p ->turn = t;
	p ->next = NULL;

	return p;
}


part* newPartTail(int posX, int posY, int d, part *oldTail){
	part *p = malloc(sizeof(part));
	p ->x = posX;
	p ->y = posY;
	p ->direction = d;
	p ->turn = d;
	p ->next = oldTail;
	//	oldTail ->next = p;
	return p;
}

