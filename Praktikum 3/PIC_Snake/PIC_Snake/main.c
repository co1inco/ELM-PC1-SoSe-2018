/*
 * PIC_P3_V1.c
 *
 * Created: 14.05.2018 21:14:17
 * Author : Colin
 */ 

#include <avr/io.h>

#include "s65_stk600.h"
#include "snakeLib.h"

#define  F_CPU  8000000
#include <util/delay.h>


int game(bool autostart){
	uint8_t kDown;        // keys down


//	u8* fb = gfxGetFramebuffer(GFX_TOP, GFX_RIGHT, NULL, NULL);
	int y_resolution = DISPWIDTH;
//	memset(fb, 0, y_resolution*DISPHEIGHT*3);
	int size = 10;
	
	int direction = 1;
	int pos_x		= DISPHEIGHT/2;
	int pos_y		= y_resolution/2;
	int score 	= 0;
	int speed     = 15; //smaller = faster
	bool hitEnd = false;
	int acceleration = 0;
	int accelerationNext = 5;

	int wait = 0;
	
	bool debugMode = false; //----debugmode default-----
	
	int oldDirection = 0;
	int partDirection = 0;
	int turn = 0;
	int partTurn = 0;

	int restart = 0;
	bool pause = !autostart;
	
	int appleY = (rand() % y_resolution/size) * size;
	int appleX = (rand() % DISPHEIGHT/size) * size;
	
	
	color red   = { 0x0,  0x0, 0xFF};

	
	part *start = NULL;	//Tail
	part *last = NULL;	//Head
	part *tmpPart = NULL;
	part *tmpPart2 = NULL; //Need to darw snake and cleanup part list
	
	last = newPart(pos_x,pos_y, direction, direction);
	if (start == NULL) start = last;
	
	tmpPart = last;
	last = newPart(pos_x,pos_y, direction, direction);	//new part => last part in list
	tmpPart ->next = last;								//tmpLast => currently next-to-last -> add the new last part

	
	// Main loop
	while (1)
	{
				
//		hidScanInput();
		kDown = hidKeysDown();

		if (kDown & KEY_START) pause = !pause;
		
		if (hitEnd) pause = true;
		
		if (!pause){
			
//			memset(fb, 5, y_resolution*DISPHEIGHT*3);
			lcd_ClearScreen(0x0000);
			
//			if (debugMode) {
//				memset(fb, 0x88, y_resolution*DISPHEIGHT*3);
//				debugGrid(fb);
//				} else {
// 				memset(fb, 5, y_resolution*DISPHEIGHT*3);
//			}
			
			if ((kDown & KEY_RIGHT) && oldDirection != 3) direction = 1; 		//Right - 1
			if ((kDown & KEY_UP	  ) && oldDirection != 4) direction = 2;		//Up	- 2
			if ((kDown & KEY_LEFT ) && oldDirection != 1) direction = 3;		//Left	- 3
			if ((kDown & KEY_DOWN ) && oldDirection != 2) direction = 4;		//Down	- 4
			
			
			//Speed control
			if (acceleration == accelerationNext){
				if (speed > 5) speed = speed - 2;
				acceleration = 0;
				accelerationNext = accelerationNext + 2;
			}
			
			if (debugMode == true) {
				if (kDown & KEY_A){			//add new element
					tmpPart = last;
					last = newPart(pos_x,pos_y, direction, direction);
					tmpPart ->next = last;

					score++;
					acceleration++;
				}
				if (kDown & KEY_B) speed--; //speed up
			}
			
			
			if (wait > speed && !hitEnd){	//move forward and border detection
				switch(direction){
					case (1):
						pos_y = pos_y + size;			  // move "size" forward
						if (pos_y > y_resolution - size){ // check if head hit the border
							pos_y = y_resolution - size;
							hitEnd = true;
						}
						break;
					case (2):
						pos_x = pos_x + size;
						if (pos_x > DISPHEIGHT-size){
							pos_x = DISPHEIGHT-size;
							hitEnd = true;
						}
						break;
					case (3):
						pos_y = pos_y - size;
						if (pos_y < 0){
							pos_y = 0;
							hitEnd = true;
						}
						break;
					case(4):
						pos_x = pos_x - size;
						if (pos_x < 0){
							pos_x = 0;
							hitEnd = true;
						}
						break;
					default:
						break;
				}

				//testfor hit self
				tmpPart = start;
				if (score > 1){
					while (tmpPart != NULL){
						if (pos_x == tmpPart ->x && pos_y == tmpPart ->y) hitEnd = true;
						tmpPart = tmpPart ->next;
					}
				}
				
				//testfor apple
				if (pos_x == appleX && pos_y == appleY) {
					start = newPartTail(start ->x,start ->y, start ->direction, start);
					score++;
					acceleration++;
					
					srand(time(NULL));
					appleY = (rand() % y_resolution/size) * size;
					appleX = (rand() % DISPHEIGHT/size) * size;
				}
				
				turn = direction;
				if (direction != oldDirection){
					if (direction == 1){
						if (oldDirection == 2) turn = 6;
						if (oldDirection == 4) turn = 7;
						} else if (direction == 2){
						if (oldDirection == 1) turn = 8;
						if (oldDirection == 3) turn = 7;
						} else if (direction == 3){
						if (oldDirection == 2) turn = 5;
						if (oldDirection == 4) turn = 8;
						} else if (direction == 4){
						if (oldDirection == 1) turn = 5;
						if (oldDirection == 3) turn = 6;
					}
					last ->turn = turn;
					last ->direction = direction;
				}
				
				// add the new head to list
				tmpPart = last;
				last = newPart(pos_x, pos_y, direction, direction);
				tmpPart ->next = last;

				//remove old tail from list
				tmpPart = start;
				start = tmpPart ->next;
				free(tmpPart);
				
				wait = 0;
				oldDirection = direction;
				
				}
			
			
			//---- Draw ----
			tmpPart = start;
//			drawSpriteC(fb, tmpPart ->x+tmpPart->y*DISPHEIGHT , tmpPart ->direction, 3);

			drawSpriteC(tmpPart ->x, tmpPart->y , tmpPart ->direction, 3);
			
			tmpPart = tmpPart ->next;
			for (; tmpPart != NULL; tmpPart = tmpPart2){
				partDirection = tmpPart ->direction;
				partTurn = tmpPart ->turn;
				tmpPart2 = tmpPart ->next;
				if (tmpPart2 != NULL) {
					if (partDirection != partTurn) 
						drawSpriteC(tmpPart ->x, tmpPart->y , partTurn, 4);
					else 
						drawSpriteC( tmpPart ->x, tmpPart->y , partDirection, 2);
				}
				if (tmpPart2 == NULL) 
					drawSpriteC(tmpPart ->x, tmpPart->y , direction, 1);
			}
			drawSpriteC( appleX, appleY, 1, 5);

			
			//---- Consol output ----
//			consoleClear;
/*			printf("\e[1;1H\e[2J");
			printf("\x1b[1;0H SCORE: %i", score);
			if (debugMode == true) {
				printf("\x1b[2;0H X:    		%i  ", pos_x);
				printf("\x1b[3;0H Y:    		%i  ", pos_y);
				printf("\x1b[4;0H End:  		%i  ", hitEnd);
				printf("\x1b[5;0H Score:		%i  ", score);
				printf("\x1b[6;0H Speed:		%i  ", speed);
				printf("\x1b[7;0H SpeedNext:	%i	", accelerationNext);
				printf("\x1b[8;0H ApplX:		%i  ", appleX);
				printf("\x1b[9;0H ApplY:		%i  ", appleY);
				printf("\x1b[10;0H Debug:		%i	", debugMode);
			} */
		
				
			// Flush and swap framebuffers
//			gfxFlushBuffers();
//			gfxSwapBuffers();
			_delay_ms(2); // 100/50
			wait++;
			
		} else {	//when pause
			
//							printf("\x1b[12;%iH [PAUSE] ", (y_resolution/8)/6+3); //22
//			if (!hitEnd)	printf("\x1b[14;%iH Press [START]  to continue", (y_resolution/8)/8);
//							printf("\x1b[15;%iH Press [SELECT] to exit", (y_resolution/8)/8);
//			 if (hitEnd)	printf("\x1b[16;%iH Press [START] or (A) to restart", (y_resolution/8)/8);
//			 else 			printf("\x1b[16;%iH Press (A) to restart", (y_resolution/8)/8);
	
	
			
			if (kDown & KEY_SELECT){
				restart = 0;
				break;
			}
			if (kDown & KEY_A){
				restart = 1;
				break;
			}
//			if (kDown & KEY_X){
//				debugMode = !debugMode;
//			}
			if ((kDown & KEY_START) && hitEnd) {
				restart = 2;
				break;
			}
		}
		
	}
	
	//Cleanup list
	tmpPart = start;
	tmpPart2 = NULL;
	for (; tmpPart != NULL; tmpPart = tmpPart2){
		tmpPart2 = tmpPart ->next;
		free(tmpPart);
	}
	return restart;
}


int main(void)
{
	lcd_Init();
	lcd_ClearScreen(0xffff);
	
	int play = 1;
	bool autorun = false;
  
	while (play){
		if (play==2) autorun = true;
		play = game(autorun);
	}	
	
}

