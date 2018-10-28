#include <stdio.h>
#include <stdlib.h>

typedef struct chainE{
	int num;
	struct chainE *next;
} chain;



int main(){
	int input;
	
	chain *tmpElement;
	chain *firs = tmpElement;
	chain *tmpE2 = NULL;
	
	do {
		if (scanf("%i", &input)){
			printf("Add: %i\n", input);
			tmpElement ->num = input;
			tmpE2 = malloc(sizeof(chain));
			printf("malloc");
			tmpElement ->next = tmpE2;
			printf("add");
			tmpElement = tmpElement ->next;
			
		} else {
			printf("wrong input\n");
		}
		fflush(stdin);
		
	} while (input != EOF);
	
	printf("END");
	
}