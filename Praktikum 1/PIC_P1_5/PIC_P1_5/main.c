/*
 * PIC_P1_5.c
 *
 * Created: 24.04.2018 15:04:41
 * Author : Colin, Bastian
 */ 

#define false (0)
#define true (1)

#include <avr/io.h>

#define  F_CPU  8000000
#include <util/delay.h>

#include "led.h"

int main(void)
{
    Init_D();
	
	uint8_t i;
	
    while (1) 
    {
		
		for (i=0; i<=6; i++){
			PORTD = ~(1 << i); //setze die i+1.te led von rechts auf 1
			_delay_ms(200);
		}
		
		for (i=0; i<=6; i++){
			PORTD = ~(0x80 >> i); // setze die i+1te led von links auf 1
			_delay_ms(200);
		}
    }
}



/*
int main(void)
{
    Init_D();
	
	uint8_t a = 1;
	uint8_t shiftRight = false;
	
    while (1) 
    {
		if (shiftRight==false){
			if (a!=0x80) 
				a = a << 1;
			else
				shiftRight = true;
				
		} else {
			if (a!=0x01)
				a = a >> 1;
			else
				shiftRight = false;
		}
			
					
		PORTD = ~a;		
		_delay_ms(200);
		
    }
}
*/

/*
int main(void)
{
    Init_D();
	
	uint8_t a = 0;
	
    while (1) 
    {
		if (a==0)
			a = 1;
		else
			a =a << 1;			
		PORTD = ~a;		
		_delay_ms(200);
		
    }
}
*/
