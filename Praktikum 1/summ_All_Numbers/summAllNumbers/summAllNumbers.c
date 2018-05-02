//============================================================================== 
// 
// Fachhochschule Bielefeld – Fachbereich Technik im Aufbau
// 
//==============================================================================
// \file summAllNumbers.c
// 
// \brief Demo project for debugging
// 
// \version 1.0, 20.05.2011, created
// 
// \author ASimon
//==============================================================================


//------------------------------------------------------------------------
// Include files
//------------------------------------------------------------------------
#include <avr/io.h>


//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------
//=== Function: main ===========================================================
// 
// \brief Add all numbers between 0 and 10
// 
// \ return The return value of the main function
//==============================================================================
int main(void)
{
	// initialize PortD
  DDRD  = 0xff;
  PORTD = 0xff;
  
  uint8_t counter;
  uint16_t result;
  
  result = 0;
  
  // Loop for adding all numbers between 0 and 10
  for (counter=0; counter<=10; counter++)
  {
	  result = result+counter;
  }
  
  // Show result on LED
  PORTD = ~result;
}