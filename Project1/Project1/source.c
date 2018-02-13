// Aufgabe 7

#include <stdio.h>

int main() {
	int d = 0;
	int sum = 0;

	while (d != -1) {
		scanf("%i", d);
		sum = sum + d;
	}

	printf("%i", sum);

	return 0;
}

