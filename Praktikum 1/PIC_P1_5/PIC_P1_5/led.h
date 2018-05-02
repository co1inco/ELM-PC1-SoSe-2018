/*
 * IncFile1.h
 *
 * Created: 24.04.2018 16:03:57
 *  Author: Colin, Bastian
 */ 


#ifndef LED_H_
#define LED_H_

#include <avr/io.h>

void Init_D(void);

void LedSetOnMask(uint8_t ledMask);	// ledMask ist 8-Bit-Maske
void LedSetOffMaske(uint8_t ledMask);

void LedToggle(void);

void LedAllOff(void);
void LedAllOn(void);

void LedInit_A_D(void);

uint8_t getButtonPressed(void);

#endif /* LED_H */