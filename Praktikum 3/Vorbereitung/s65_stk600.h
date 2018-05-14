/** -------------------------------------------------------------
*
* @file s65_stk600.h
*
* @brief All functions to use the expansion board for the STK-600
*
* @author ASimon
*
* @date 2011/05/12
*
* -------------------------------------------------------------- */


#ifndef S65_STK600_H_
#define S65_STK600_H_

//---------------------------------------------------------------------------------------------------------------
// Defines
//---------------------------------------------------------------------------------------------------------------

/**
 * @def F_CPU
 * The CPU frequency
 */
#define F_CPU 8000000UL


/**
 * @name Colors
 * Define some colors
 * @{
 */
#define LCD_COLOR_WHITE     0xFFFF
#define LCD_COLOR_BLACK     0x0000
#define LCD_COLOR_RED       0xF800
#define LCD_COLOR_BLUE      0x001F
#define LCD_COLOR_GREEN     0x07E0
#define LCD_COLOR_YELLOW    0xFFE0
#define LCD_COLOR_ORANGE    0xFD20
/** @} */

#define USE_TIMER
#define USE_INCENC
//#define USE_DIGITAL
//#define USE_DAC
//#define USE_TOUCH

//#define USE_LCD_L2F50
//#define USE_LCD_LPH88
#define USE_LCD_LS020

//#define USE_LCD_MI0283QT2
//#define USE_LCD_PARALLEL

//#define USE_HUGE_FONT


#define FONT_START                    (0x20)

#ifdef USE_HUGE_FONT
#define FONT_WIDTH                    (32)
#define FONT_HEIGHT                   (53)
#else
#define FONT_WIDTH                    (8)
#define FONT_HEIGHT                   (14)
#endif // USE_HUGE_FONT

#if (defined USE_LCD_MI0283QT2 && (defined USE_LCD_L2F50 || defined USE_LCD_LPH88 || defined USE_LCD_LS020)) || \
    (defined USE_LCD_L2F50 && (defined USE_LCD_MI0283QT2 || defined USE_LCD_LPH88 || defined USE_LCD_LS020)) || \
	(defined USE_LCD_LPH88 && (defined USE_LCD_L2F50 || defined USE_LCD_MI0283QT2 || defined USE_LCD_LS020)) || \
	(defined USE_LCD_LS020 && (defined USE_LCD_L2F50 || defined USE_LCD_LPH88 || defined USE_LCD_MI0283QT2))
#error "Only use one LCD type"
#endif

#ifdef USE_LCD_MI0283QT2
#define USE_BIG_SCREEN
#endif

	
/**
 * @name Lcd-resolution
 * Define the lcd resolution
 * @{
 */
#ifdef USE_BIG_SCREEN
#define _LCD_WIDTH    (320)
#define _LCD_HEIGHT   (240)
#else
#define _LCD_WIDTH    (176)
#define _LCD_HEIGHT   (132)
#endif

#ifdef LCD_ROTATE
# define LCD_WIDTH     _LCD_HEIGHT
# define LCD_HEIGHT    _LCD_WIDTH
#else
# define LCD_WIDTH     _LCD_WIDTH
# define LCD_HEIGHT    _LCD_HEIGHT
#endif
/** @} */


//---------------------------------------------------------------------------------------------------------------
// Includes
//---------------------------------------------------------------------------------------------------------------
#include <util/delay.h>
#include <stdint.h>
#include <stdbool.h>




//---------------------------------------------------------------------------------------------------------------
// Functions
//---------------------------------------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------------------------------
// Incremental-Encoder functions
//---------------------------------------------------------------------------------------------------------------

#ifdef USE_INCENC

// Initializes the incremental-encoder.
void incenc_Init(void (*funcIncPressed)(), void (*funcIncReleased)(), void (*funcIncMovedLeft)(), void (*funcIncMovedRight)());

int16_t incenc_GetPos(bool reset);    // Get the position change of IncEnc
bool incenc_GetPressed(bool reset);   // Returns true if Inc.Enc. was pressed
bool incenc_GetReleased(bool reset);  // Returns true if Inc.Enc. was released
bool incenc_GetPressedState();        // The actual status if Inc.Enc is pressed or not

#endif


//---------------------------------------------------------------------------------------------------------------
// Functions for the LCD
//---------------------------------------------------------------------------------------------------------------
/* Initializes the screen. */
void  lcd_Init();

/* Clears the screen. */
void  lcd_ClearScreen(uint16_t color);

#ifdef USE_BIG_SCREEN

/* Draws a pixel. */
void  lcd_DrawPixel(uint16_t x, uint16_t y, uint16_t color);
/* Draws a rectangle. */
void  lcd_DrawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t frameColor, uint16_t frameWidth);
/* Draws a filled rectangle. */
void  lcd_DrawFilledRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
/* Draws a line. */
void  lcd_DrawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);

/* Draws a letter on the LCD. */
void  lcd_DrawChar(uint16_t x, uint16_t y, uint8_t c, uint16_t textcolor, uint16_t backcolor);
/* Draws a letter horizontally. */
void  lcd_DrawChar90(uint16_t x, uint16_t y, uint8_t c, uint16_t textcolor, uint16_t backcolor);
/* Draws a string horizontally. */
void  lcd_DrawString(uint16_t x, uint16_t y, char *txt, uint16_t textcolor, uint16_t backcolor);
/* Draws a bitmap */
void lcd_DrawBitmap(uint16_t x, uint16_t y, uint16_t bitmap[], uint16_t width, uint16_t height, uint16_t fgcolor, uint16_t bgcolor);
/* Draws an indexed bitmap */
void lcd_DrawBitmapInd(const uint8_t* data, const uint16_t* palette, uint8_t x, uint8_t y, uint8_t width, uint8_t height);

#else

/* Draws a pixel. */
void  lcd_DrawPixel(uint8_t x, uint8_t y, uint16_t color);
/* Draws a rectangle. */
void  lcd_DrawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t frameColor, uint8_t frameWidth);
/* Draws a filled rectangle. */
void  lcd_DrawFilledRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);
/* Draws a line. */
void  lcd_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);

/* Draws a letter on the LCD. */
void  lcd_DrawChar(uint8_t x, uint8_t y, uint8_t c, uint16_t textcolor, uint16_t backcolor);
/* Draws a letter horizontally. */
void  lcd_DrawChar90(uint8_t x, uint8_t y, uint8_t c, uint16_t textcolor, uint16_t backcolor);
/* Draws a string horizontally. */
void  lcd_DrawString(uint8_t x, uint8_t y, char *txt, uint16_t textcolor, uint16_t backcolor);
/* Draws a bitmap */
void lcd_DrawBitmap(uint8_t x, uint8_t y, uint16_t bitmap[], uint8_t width, uint8_t height, uint16_t fgcolor, uint16_t bgcolor);

#endif

/* Combines the 3-color-values to one 16bit-color. */
uint16_t lcd_Get16BitColor(uint8_t r,uint8_t g,uint8_t b);
/* Converts RGB color to 16bit color. */
uint16_t lcd_RGBto16BitColor(uint8_t r,uint8_t g,uint8_t b);


//---------------------------------------------------------------------------------------------------------------
// Timer functions
//---------------------------------------------------------------------------------------------------------------

#ifdef USE_TIMER

// Initializes the timer
void timer0_PollInit(uint8_t time);
void timer0_Init(void (*func)(), uint8_t time);
void timer0_Start();
void timer0_Stop();
bool timer0_HasTriggered();

void timer1_PollInit(uint8_t time);
void timer1_Init(void (*func)(), uint8_t time);
void timer1_Start();
void timer1_Stop();
bool timer1_HasTriggered();

#endif


//---------------------------------------------------------------------------------------------------------------
// Functions for digital and analog input and output pins
//---------------------------------------------------------------------------------------------------------------

/* Initializes analog input sources. */
void adc_Init();
/* Reads value from ADC pin 1. */
uint16_t adc_Read1();
/* Reads value from ADC pin 2. */
uint16_t adc_Read2();

/* Initializes digital pins. */
void digital_Init();
/* Sets signal of digital output pin 1. */
void digital_Set1(bool value);
/* Sets signal of digital output pin 2. */
void digital_Set2(bool value);
/* Sets signal of digital output pin 3. */
void digital_Set3(bool value);
/* Sets signal of digital output pin 4. */
void digital_Set4(bool value);
/* Reads signal form digital input pin 1. */
bool digital_Read1();
/* Reads signal form digital input pin 2. */
bool digital_Read2();
/* Reads signal form digital input pin 3. */
bool digital_Read3();
/* Reads signal form digital input pin 4. */
bool digital_Read4();

/* Initializes the DAC. */
void dac_Init();
/* Sets signal of analog output pin 1. */
void dac_Set1(uint8_t value);
/* Sets signal of analog output pin 2. */
void dac_Set2(uint8_t value);


void uart_Init(void (*funcUARTReceived)(uint8_t));
void uart_SendByte(uint8_t byte);
void uart_SendData(uint8_t *data, uint16_t size);

#endif /* S65_STK600_H_ */