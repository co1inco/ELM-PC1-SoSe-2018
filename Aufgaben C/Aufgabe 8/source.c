// Aufgabe 7

#include <stdio.h>

int main() {
	int forSum = 0;
	int i;
	for (i = 0; i<=100; i++){
		forSum = forSum + i;
	}
	
	int whileSum = 0;
	int j = 0;
	while ( j <= 100){
		whileSum = whileSum + j;
		j = j + 1;
	}
	
	printf("forSum = %i \nwhileSum = %i", forSum, whileSum);

	return 0;
}