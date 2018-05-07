/*
 * PIC_P2_4.c
 *
 * Created: 07.05.2018 09:22:13
 * Author : Colin, Bastian
 */ 

#define  F_CPU  8000000
#include <util/delay.h>

#include <avr/io.h>

#include "s65_stk600.h"


int main(void)
{
	DDRD = 0xff;
	PORTD = 0xff;
	
	uint16_t value = 0;
	
	incenc_Init (0,0,0,0);
	
	int16_t step; // !!! no u ->(unsigned) because we need negative numbers
	uint16_t led = 0x08;
	while (1){
		step = incenc_GetPos(true);
		
		if (step > 0){
			if (led == 0x80){
				PORTD = ~0x00;
				_delay_ms(100);
			} else {
				led = led << 1;
			}
		} 
		if (step < 0){
			if (led == 0x01){
				PORTD = ~0x00;
				_delay_ms(100);
			} else {
				led = led >> 1;
			}
		}
		
		PORTD = ~led;
	}
}


