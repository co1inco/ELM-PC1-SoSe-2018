#include <stdio.h>

int main(){
	
//	while (1){
		char z1;
	
		scanf("%c", &z1);
	
		switch (z1){
			case 'g':
				printf("Go!");
				break;
			case 'y':
				printf("Carefull!");
				break;
			case 'r':
				printf("STOP!");
				break;
			default:
				printf("wrong Input");
				break;
		}
//	}	
	
	return 0;
}
