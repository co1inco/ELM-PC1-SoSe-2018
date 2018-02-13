#include <stdio.h>

int main(){
	int z1;
	int z2;
	
	printf("Zahl 1: ");
	scanf(" %i", &z1);
	printf("\nZahl 2: ");
	scanf("%i", &z2);
	
	printf("\nSumme von %i und %i ist %i\n", z1, z2, z1+z2);
	printf("Differenz von %i und %i ist %i\n", z1, z2 , z1-z2);
	printf("Produkt von %i und %i ist %i\n", z1, z2, z1*z2);
	printf("Quotient von %i und %i ist %i\n", z1, z2, z1/z2);
	
	
	return 0;
}
