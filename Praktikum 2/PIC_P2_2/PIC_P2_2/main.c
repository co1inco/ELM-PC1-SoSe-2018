/*
 * PIC_P2_2.c
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
	
	uint16_t value = 0;
	
	adc_Init();
	
	uint16_t tempStart = value_to_celsius(adc_Read2());
	uint16_t cel;

	uint16_t led;
	
	while (1){
		value = adc_Read2();
		cel = value_to_celsius(value);
		led = value_to_led(tempStart-1, tempStart+6, cel);
		setLedvalue(led);
	}
}

