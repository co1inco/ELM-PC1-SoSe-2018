#include <stdio.h>
#include <string.h>

int countNum(char a[20]){
	int i;
	int j;
	int count = 0;
	char num[10] = {'1','2','3','4','5','6','7','8','9','0'};
	
	for (i=0; i<strlen(a); i++){
		for (j=0; j<strlen(num); j++){
			if (*(a+i) == *(num+j)) count++;
		}
	}
	return count;
}

void printA(char a[20]){
	int i;
	for (i=0; i<strlen(a); i++){
		printf("'%c',", a[i]);
	}
	printf("\n");
}

void main(){
	char a[20] = {'1','2',3,4,5,6,7,8,9,10};
	int l = strlen(a);
	printf("Len: %i\n", l);
	printf("Num: %i\n", countNum(a));
	a[5] = '\0';
	printA(a);
	printf("Len: %i\n", l);	
	
	char c1;
	char & c2 = &c1;
	
	
}