/*
 * PIC_P2_Z1.c
 *
 * Created: 07.05.2018 18:50:15
 * Author : Colin
 */ 

#include <avr/io.h>

#include <avr/io.h>

#include "coLib1.h"

#include "s65_stk600.h"


int main(void)
{
	
	DDRD = 0xff;
	PORTD = 0xff;
		
	adc_Init();
	
	uint16_t value;
	uint8_t led;
		
    while (1) {
		value = value_to_led(0, 1023, adc_Read1());
		
		led = 0x00;
		for (; value>0x00; value=value>>1){
			led = led | value;
		}
		PORTD = ~led;    
    }
}

