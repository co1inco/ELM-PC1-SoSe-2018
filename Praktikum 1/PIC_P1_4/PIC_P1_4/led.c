#include <avr/io.h>
#include "led.h"

void Init_D(void)
{
	DDRD = 0xFF;                    // Port D: Alle Bits auf Ausgabe
	PORTD = 0xFF;                   // Negiert: Alle LEDs ausschalten
}

void LedSetOnMask(uint8_t ledMask)	// ledMask ist 8-Bit-Maske
{									// Negierte Logik der LEDs beachten!
	uint8_t ledTemp = ~ ledMask;     // Maske negiert in Hilfsvariable
	PORTD = PORTD & ledTemp;         // die 1 in der Maske (= Bit 0 in ledTemp) setzt sich durch oder sehr kompakt (1 Zeile reicht):  PORTD &= ~ledMask;
}

void LedSetOffMaske(uint8_t ledMask){
	PORTD = PORTD | ledMask;
}

void LedToggle(void){
	PORTD = ~PORTD;
}

void LedAllOff(void){
	PORTD = 0xFF;
}

void LedAllOn(void){
	PORTD = 0x00;
}

void LedInit_A_D(void){
	DDRD = 0xff;
	LedAllOff();
	
	DDRA = 0x00;
}

uint8_t getButtonPressed(void){
	return ~PINA;
}