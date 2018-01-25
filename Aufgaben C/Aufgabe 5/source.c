#include <stdio.h>

int main(){
	
//	while (1){
		char z1;
	
		scanf("%c", &z1);
	
		if (z1 == 'g' || z1 == 'y' || z1 == 'r'){
			if (z1 == 'g')
				printf("Go!");
			if (z1 == 'y')
				printf("Carefull!");
			if (z1 == 'r')
				printf("STOP!");
		} else 
			printf("wrong Input");
//	}
	
	return 0;
}
