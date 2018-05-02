/*
 * PIC_P1_1.c
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
	PORTD = 0b00000000; 
    /* Replace with your application code */
    while (1) 
    {
		PORTD = PORTD ^ 0b00000001;
		_delay_ms(500);
    }
}

