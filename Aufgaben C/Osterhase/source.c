#include <stdio.h>
#define round(x) ((x)>=0?(long)((x)+0.5):(long)((x)-0.5))

float expo(float b, int e){
	float tmp = b;
	for (; e>1; e--){
		tmp = tmp * b;
	}
	return tmp;
}

int eggCalc(int eggMax, int redMax, int eggCount, int redCount, int pathCount){
	
	if (redCount == redMax) 		return pathCount+1;
	else if (eggCount >= eggMax) 	return pathCount;
	
	pathCount = eggCalc(eggMax, redMax, eggCount+1, redCount+1, pathCount);
	pathCount = eggCalc(eggMax, redMax, eggCount+1, redCount  , pathCount);
	
	return pathCount;
}

int main(){
	int eggMax;
	int redMax;
	float redProp;
	
	int eggCount = 0;
	int redCount = 0;
	int pathCount = 0;
	
	printf("Max eggs: "); scanf("%i", &eggMax);
	printf("Max red:  "); scanf("%i", &redMax);
	printf("Prop red: "); scanf("%f", &redProp);
	
	pathCount = eggCalc(eggMax, redMax, eggCount, redCount  , pathCount); //Magic
	
	float branchPropability;
	branchPropability = expo(redProp, redMax) * expo((1-redProp), (eggMax-redMax));
	float redCountProp = branchPropability * pathCount;
	
	printf("Path: %i \n", pathCount);
	printf("Pathprop: %f\n", branchPropability);
	printf("Propability of %i red eggs of %i eggs with a propability of %.2f is: %.2f or %d%% \n", redMax, eggMax, redProp, redCountProp, round(redCountProp*100));
	
	return 0;
}