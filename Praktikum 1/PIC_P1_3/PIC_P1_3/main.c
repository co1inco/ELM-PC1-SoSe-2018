/*
 * PIC_P1_3.c
 *
 * Created: 24.04.2018 13:52:40
 * Author : Colin
 */ 

#include <avr/io.h>


int main(void)
{
	uint8_t input;
	
	DDRA = 0b00000000; //Buttons as input
	
	DDRD = 0b11111111; //LEDs as output
	
    /* Replace with your application code */
    while (1) 
    {
		input = PINA; // set input to pressed buttons
		PORTD = input; // set LEDs to input
    }
}

