#include <stdio.h>

int main(){
	int z1;
//	int z2;
	
	scanf("%i", &z1);
//	scanf("%i", &z2);
	
	if (z1 < 0)
		z1 = z1 * -1;
	
	printf("%i", z1);
	
	return 0;
}
