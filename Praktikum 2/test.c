#include <stdio.h>
#include <math.h>

/* Arduino map function
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
} */


int map(int value, int fromLow, int fromHigh, int toLow, int toHigh){
	// entpricht gekürzt genau der arduino map funktion \o/
	int fromDif = fromHigh - fromLow;
	int toDif   = toHigh - toLow;
	value = value - fromLow;
	
	int fVal = (toDif/100.0 ) * ((100.0/fromDif)*value);
	
	return toLow+fVal;	
	
}


int value_to_led(int value, int lower, int upper){
	int led = map(value, lower, upper, 0, 8);
	return 0x01 << led;
}

int value_to_celsius(int value){
	int kel = map(value, 0, 1023, 0, 500); // 500 => 5V
	return kel - 273; // 273,15	
}
	
	


void main(){
	int val = 9;
	int out;

	for (val=100; val <=300; val=val+50){
		printf("%i %i %i %i\n", map(val, 100, 300, 0, 8), map(val, 300, 100, 0, 8), map(val, 100, 300, 8, 0), map(val, 160, 240, 0, 8));
	}
	
	
	
/*	
	for (val=1; val != 0; scanf("%i", &val)){
		out = map(val, 100, 300, 0, 8);
//		out = value_to_led(val, 100, 300);
//		out = value_to_celsius(val);
		
		printf("\n");
	
		printf("\b - Map: %i\n", out);  
	}
*/


}