/*
 * CFile1.c
 *
 * Created: 06.05.2018 17:13:46
 *  Author: Colin
 */ 


uint16_t map(uint16_t value, uint16_t fromLow, uint16_t fromHigh, uint16_t toLow, uint16_t toHigh){
	// not teste what happens if upper and lower are switcht!!
	uint16_t fromDif = fromHigh - fromLow;
	uint16_t toDif   = toHigh - toLow;
	
	value = value - fromLow;
	
	//	float perc = (100.0/fromDif) * value;
	uint16_t fVal = round( (toDif/100.0 ) * ((100.0/fromDif)*value) );
	
	return toLow+fVal;
}


uint16_t value_to_led(uint16_t value, uint16_t lower, uint16_t upper){
	uint16_t led = map(value, lower, upper, 0, 8);
	return 0x01 << led;
}

uint16_t value_to_celsius(uint16_t value){
	uint16_t kel = map(value, 0, 1023, 0, 500); // 500 => 5V
	return kel - 273; // 273,15
}