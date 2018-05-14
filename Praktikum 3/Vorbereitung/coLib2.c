#define RIGHT (1)
#define UP (2)
#define LEFT (3)
#define DOWN (4)


uint8_t appleSprite[10][10] = {
	{ 0 ,0, 2, 2, 0, 3, 3, 0, 0, 0},
	{ 0, 0, 0, 0, 2, 3, 0, 0, 0, 0},
	{ 0, 5, 5, 5, 3, 0, 5, 5, 5, 0},
	{ 0, 5, 5, 5, 3, 5, 5, 5, 5, 5},
	{ 5, 5, 5, 5, 5, 5, 6, 6, 5, 5},
	{ 5, 5, 5, 5, 5, 5, 6, 6, 5, 5},
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5},
	{ 5, 5, 5, 5, 5, 5, 5, 5, 5, 0},
	{ 0, 5, 5, 5, 5, 5, 5, 5, 5, 0},
	{ 0, 0, 5, 5, 0, 0, 5, 5, 0, 0},
};

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

/*
#define LCD_COLOR_WHITE     0xFFFF
#define LCD_COLOR_BLACK     0x0000
#define LCD_COLOR_RED       0xF800
#define LCD_COLOR_BLUE      0x001F
#define LCD_COLOR_GREEN     0x07E0
#define LCD_COLOR_YELLOW    0xFFE0
#define LCD_COLOR_ORANGE    0xFD20
*/

void drawPixel_int2col(fb, uint16_t posX, uint16_t posY,  uint8_t col){
	switch (col)
	{
		case 1:
			lcd_DrawPixel(posX, posY, white);
			break;
		case 2:
			lcd_DrawPixel(posX, posY, green);
			break;
		case 3:
			lcd_DrawPixel(posX, posY, black);
			break;
		case 4:
			lcd_DrawPixel(posX, posY, black);
			break;
			
		case 5:
			lcd_DrawPixel(posX, posY, red);
			break;
		case 6:
			lcd_DrawPixel(posX, posY, red);  //brighter red
			break;
			
	}
	if (sprite[spriteX][spriteY] == 1){
		drawPixel( fb, pos, spriteY, spriteX, white);
	} 
	if (sprite[spriteX][spriteY] == 2){
		drawPixel( fb, pos, spriteY, spriteX, snakeGreen);
	} 
	if (sprite[spriteX][spriteY] == 3){
		drawPixel( fb, pos, spriteY, spriteX, snakeStripes);
	} 
	if (sprite[spriteX][spriteY] == 4){
		drawPixel( fb, pos, spriteY, spriteX, black);
}


void drawSprite(u8* fb, uint16_t posx,uint16_t posx, uint8_t direction, uint8_t sprite[10][10]){
	int spriteX;
	int spriteY;
	int dispHei;
	int dispWid;
	
	switch (direction) {
		
		case 1:		// Right
			for (spriteY=0 ; spriteY < 10; spriteY++){
				for (spriteX=0; spriteX < 10; spriteX++){
					drawPixel_int2col(posx+spriteX, posy+spriteY, sprite[spriteY][spriteX])			
				}
			}
			break;
			
		case 2:		// Up
			for (spriteY=0; spriteY < 10; spriteY++){
				dispWid = 9;
				for (spriteX=0; spriteX < 10; spriteX++){
					drawPixel_int2col(posx+dispWid, posy+spriteY, sprite[spriteY][spriteX])
					dispWid--;				
				}
			}
			break;
			
		case 3:		// Left
			dispHei = 10;
			for (spriteY=0; spriteY < 10; spriteY++){
				dispWid = 10;
				dispHei--;
				for (spriteX=0; spriteX < 10; spriteX++){
					drawPixel_int2col(posx+dispWid-1, posy+dispHei, sprite[spriteY][spriteX])
					dispWid--;
				}
			}
			break;
			
		case 4:		// Down
			dispHei = 9;
			for (spriteY=0; spriteY < 10; spriteY++){
				dispWid = 0;
				for (spriteX=0; spriteX < 10; spriteX++){
					drawPixel_int2col(posx+dispWid, posy+dispHei, sprite[spriteY][spriteX])
					dispWid++;
				}
				dispHei--;
			}
			break;
		
		default:
			break;
	}
}