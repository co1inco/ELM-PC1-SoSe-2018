/*
 * IncFile1.h
 *
 * Created: 06.05.2018 17:13:56
 *  Author: Colin
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#define DISPWIDTH (400)
#define DISPHEIGHT (240)

#define KEY_UP (1)
#define KEY_DOWN (2)
#define KEY_LEFT (4)
#define KEY_RIGHT (8)
#define KEY_START (16)
#define KEY_SELECT (32)
#define KEY_X (64)
#define KEY_A (128)
#define KEY_B (256)

#define NULL (0)

uint8_t hidKeysDown();
void hidInit();


typedef struct {
	uint8_t blue;
	uint8_t green;
	uint8_t red;
} color;

typedef struct sakeparts{
	int x;
	int y;
	int direction;
	int turn;
	struct snakeparts *next;
} part;

long map(long value,long fromLow,long fromHigh,long toLow,long toHigh);
void delay(long ms);

uint16_t value_to_led(uint16_t lower, uint16_t upper, uint16_t value);
uint16_t value_to_celsius(uint16_t value);


int col2lcd(uint8_t blue, uint8_t green, uint8_t red);
int color2lcd(color col);
void drawSprite(uint16_t posX, uint16_t posY, uint8_t direction, uint8_t sprite[10][10]);

void drawSpriteC(int posx, int posy, int direction, int type);

part* newPart(int psX, int posY, int d, int t);
part* newPartTail(int posX, int posY, int d, part *oldTail);

#endif /* INCFILE1_H_ */
