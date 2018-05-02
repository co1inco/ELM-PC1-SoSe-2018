/*
 * PIC_P1_2.c
 *
 * Created: 24.04.2018 13:05:45
 * Author : Colin, Bastian
 */ 

#define  F_CPU  8000000
#include <util/delay.h>

#include <avr/io.h>


int main(void)
{
	DDRD  = 0b11111111;
	PORTD = 0b11111111; 
    /* Replace with your application code */
	
	uint8_t counter;
	
/*
	for (counter=0; counter<=254; counter++){
		PORTD = ~(counter+1);
		_delay_ms(10);
	}
*/
	
	for (counter=0; counter<=254; counter++){
		PORTD = ~counter;
		_delay_ms(10);
	}
	PORTD = 0b00000000;

/*	
	uint16_t counter2;
	for (counter2=0; counter2<=255; counter2++){
		PORTD = ~counter2;
		_delay_ms(10);
	}
*/
	
}


