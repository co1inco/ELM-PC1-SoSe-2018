#include <stdio.h>

int main(){
	int z1;
	int z2;
	
	scanf("%i", &z1);
	scanf("%i", &z2);
	
	printf("Summe von %i und %i ist %i\n", z1, z2, z1+z2);
	printf("Differenz von %i und %i ist %i\n", z1, z2 , z1-z2);
	printf("Produkt von %i und %i ist %i\n", z1, z2, z1*z2);
	printf("Quotient von %i und %i ist %i\n", z1, z2, z1/z2);
	
	
	return 0;
}
