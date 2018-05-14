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

long map(uint16_t value, uint16_t fromLow, uint16_t fromHigh, uint16_t toLow, uint16_t toHigh);

uint16_t value_to_led(uint16_t lower, uint16_t upper, uint16_t value);
uint16_t value_to_celsius(uint16_t value);


int headSprite[10][10];
int appleSprite[10][10]; 

int headSpriteX[11][10];
int appleSpriteX[11][10]; 

int col2lcd(uint8_t blue, uint8_t green, uint8_t red);
int color2lcd(color col);
void drawSprite(uint16_t posX, uint16_t posY, uint8_t direction, uint8_t sprite[10][10])




#endif /* INCFILE1_H_ */