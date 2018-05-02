#include <stdio.h>
#include <math.h>

/* Arduino map function
long map(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
} */


int map(int value, int fromLow, int fromHigh, int toLow, int toHigh){
	// not teste what happens if upper and lower are switcht!!
	int fromDif = fromHigh - fromLow;
	int toDif   = toHigh - toLow;
	
	value = value - fromLow;
	
//	float perc = (100.0/fromDif) * value;
	int fVal = round( (toDif/100.0 ) * ((100.0/fromDif)*value) );
	
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
	
	for (val=1; val != 0; scanf("%i", &val)){
		out = value_to_led(val, 100, 300);
//		out = value_to_celsius(val);
		
		printf("\n");
	
		printf("\b - Map: %i\n", out);  
	}

}