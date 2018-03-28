// Aufgabe 2.2

#define LENGTH (10)

#include <stdio.h>

int main() {
	
	int array[LENGTH] = {1,2,3,4,5};
	int *pos = array;
	
	int i;
	for (i=0; i<LENGTH; i++){
		printf("%i\n", *pos);
		pos++;
	}
	
	

	return 0;
}