/*
 * IncFile1.h
 *
 * Created: 06.05.2018 17:13:56
 *  Author: Colin
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

typedef struct {
	uint8_t blue;
	uint8_t green;
	uint8_t red;
} color;

long map(long value,long fromLow,long fromHigh,long toLow,long toHigh);
void delay(long ms);

uint16_t value_to_led(uint16_t lower, uint16_t upper, uint16_t value);
uint16_t value_to_celsius(uint16_t value);


uint8_t headSprite[10][10];
uint8_t appleSprite[10][10]; 

uint8_t headSpriteX[11][10];
uint8_t appleSpriteX[11][10]; 

int col2lcd(uint8_t blue, uint8_t green, uint8_t red);
int color2lcd(color col);
void drawSprite(uint16_t posX, uint16_t posY, uint8_t direction, uint8_t sprite[10][10]);


#endif /* INCFILE1_H_ */
