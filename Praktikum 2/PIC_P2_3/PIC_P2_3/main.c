/*
 * PIC_P2_1.c
 *
 * Created: 07.05.2018 09:22:13
 * Author : Colin, Bastian
 */ 

#define  F_CPU  8000000
#include <util/delay.h>

#include <avr/io.h>

#include "coLib1.h"

#include "s65_stk600.h"

void setLedvalue(uint16_t led){
			if (led == 0x00){
				PORTD = ~0x01;
				_delay_ms(100);
				PORTD = ~0x00;
				_delay_ms(100);
			} else if (led == 0xff){
				PORTD = ~0x80;
				_delay_ms(100);
				PORTD = ~0x00;
				_delay_ms(100);
			} else
			PORTD = ~led;
}

int main(void)
{
	DDRD = 0xff;
	PORTD = 0xff;
	
	adc_Init();
	
	incenc_Init (0,0,0,0);
	
	uint16_t led = 0x01;
	
	while (1){
	
		if ( incenc_GetPressed(true) ){
			if (led == 0xff)
				led = 0x01;
			else
				led = (led << 1) + 1; // (00000001 << 1) -> 00000010 +1 -> 00000011 
		}
		
		PORTD = ~led;
		_delay_ms(100);
	}
}


