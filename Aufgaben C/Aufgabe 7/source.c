// Aufgabe 7

#include <stdio.h>

int main() {
	int i = 0;	
	int sum = 0;
	char d[10];

	while (i != -1) {
		
		memset(&d, 0, 10)
		scanf("%s", &d); 
		strtol(d, i);
		printf("%d, %i", d, i);
		
		sum = sum + i;
	}

	printf("%i", sum);

	return 0;
}