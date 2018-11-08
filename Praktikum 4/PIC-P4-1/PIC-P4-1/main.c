/*
 * PIC-P4-1.c
 *
 * Created: 23.05.2018 09:13:19
 * Author : Colin
 */ 

#include <avr/io.h>

#define  F_CPU  8000000
#include <util/delay.h>

#include "badg.h"
#include "hero.h"
#include "snakeLib.h"

#include "s65_stk600.h"


int main(void)
{
	incenc_Init (0,0,0,0);
	lcd_Init();
	lcd_ClearScreen(color2lcd(backgroundColor));
		
	initB();
	initH();
	
	moveB(0);
	moveH(0);
	
	uint16_t changeSpriteCounter = 0;
	
	uint16_t badGuyCounter = 0;
	uint16_t badGuyDelay = 2000;
	
	uint16_t shotCounter = 0;
	uint16_t shotDelay = 200;
	bool shotActive = false;
	bool hitB = false;
	
	int8_t step;
	
    while (1) 
    {
		
		if ((incenc_GetPressed(true) == true) && (shotActive == false) && (hitB == false)){
			initS(getyH());
			shotActive = true;
		}
		
		step = incenc_GetPos(true);
		if (step != 0)
			moveH(step);

		
		if (!hitB)
		{	
		if (changeSpriteCounter == 500){
			changeSpriteH();
		} else if (changeSpriteCounter == 250) {
			changeSpriteB();
		} else if (changeSpriteCounter > 500){
			changeSpriteCounter = 0;
		}
		changeSpriteCounter ++;
			
		if (badGuyCounter >= badGuyDelay){
			moveB();
			badGuyCounter = 0;
		}
		badGuyCounter ++;
		
		}
		
		if (shotActive){
			if (shotCounter > shotDelay){
				moveS();
				shotCounter = 0;
			}
			shotCounter ++;
			
			if (getxS() <= 10){
				shotActive = false;
				if (collisionDetection(getyB(), getyS()) == 1)
					hitB = true; 
			}
		}
		
		
		_delay_ms(1);
				
    }
}

