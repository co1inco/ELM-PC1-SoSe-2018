/*
 * CFile1.c
 *
 * Created: 06.05.2018 17:13:46
 *  Author: Colin
 */ 


#include <util/delay.h>

#include <avr/io.h>

long map(long value, long fromLow, long fromHigh, long toLow, long toHigh){
	long fromDif = fromHigh - fromLow;
	long toDif   = toHigh - toLow;
	
	value = value - fromLow;
	
	long fVal = (toDif/100.0 ) * ((100.0/fromDif)*value);
	
	return toLow+fVal;
}


uint16_t value_to_led(uint16_t lower, uint16_t upper, uint16_t value){
	if (value < lower){	
		return 0x00;
	} else if (value > upper) {		
		return 0xff;
	} else {
		uint16_t led = 0x01 << map(value, lower, upper, 0, 8);
		return led;
	}
}

uint16_t value_to_celsius(uint16_t value){
	uint16_t kel = map(value, 0, 1023, 0, 500); // 500 => 5V
	return kel - 273; // 273,15
}