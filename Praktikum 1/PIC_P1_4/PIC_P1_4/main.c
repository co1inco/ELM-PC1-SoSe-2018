/*
 * PIC_P1_4.c
 *
 * Created: 24.04.2018 14:06:23
 * Author : Colin
 */ 

#include <avr/io.h>

#define  F_CPU  8000000
#include <util/delay.h>

#include "led.h"


int main(void)
{
	LedInit_A_D();
	
	LedSetOnMask(0x0f);
	_delay_ms(500);
	LedSetOnMask(0x33);
	_delay_ms(1000);
	LedSetOffMaske(0x10);
	_delay_ms(1000);
	LedToggle();
	_delay_ms(1000);
	LedAllOff();
	_delay_ms(1000);
	LedAllOn();
	_delay_ms(1000);
	LedAllOff();
	
	while (1){
//		PORTD = ~getButtonPressed();
		LedSetOnMask(getButtonPressed());
	}
}



