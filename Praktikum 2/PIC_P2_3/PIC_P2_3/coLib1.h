/*
 * IncFile1.h
 *
 * Created: 06.05.2018 17:13:56
 *  Author: Colin
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_


uint16_t map(uint16_t value, uint16_t fromLow, uint16_t fromHigh, uint16_t toLow, uint16_t toHigh);

uint16_t value_to_led(uint16_t lower, uint16_t upper, uint16_t value);

uint16_t value_to_celsius(uint16_t value);

#endif /* INCFILE1_H_ */