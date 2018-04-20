// Aufgabe 2.2

#define LENGTH (5)

#include <stdio.h>

void extremes(int array[], int *max, int *min){
	*max = *array;
	*min = *array;

	int i;
	for (i=0; i<LENGTH; i=i+1){
		if (*array > *max) *max = *array;
		if (*array < *min) *min = *array;
		array = array+1	;
	}
}

int main() {
	
	int nums[LENGTH] = {2,1,3,4,5};
	
	int max;
	int min;
	extremes(nums, &max, &min);
	
	printf("Minimum: %i \nMaximum: %i", min, max);
	

	return 0;
}