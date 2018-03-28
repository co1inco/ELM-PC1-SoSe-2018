// Aufgabe 7

#include <stdio.h>

int whileGaus(int input){
	int whileSum = 0;
	int j = 0;
	while ( j <= input){
		whileSum = whileSum + j;
		j = j + 1;
	}
	return whileSum;
}

int forGaus(int input){
	int forSum = 0;
	int i;
	for (i = 0; i<=input; i++){
		forSum = forSum + i;
	}
	return forSum;
}

int main(int argc, char *argv[]) {
	int whileSum = -1;
	int forSum = -1;
	
	char *a = argv[1];
	int input = atoi(a);
	
	if (argc == 2){
		whileSum = whileGaus(input);
		forSum = forGaus(input);
	} else {
		whileSum = whileGaus(100);
		forSum = forGaus(100);
	}
	
//	printf("%i\n", input);
	printf("Number: %i\nforSum = %i \nwhileSum = %i",input, forSum, whileSum);

	return 0;
}