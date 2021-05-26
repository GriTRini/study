#include <stdio.h>

int main(void){

	//int celsius;
	double celsius;
	double fahr;
	
	//celsius = 100;
	//scanf("%d" , &celsius);
	scanf("%lf" , &celsius);
	fahr = (celsius* 9.0 / 5.0) + 32;
	
	printf("celsius : %f -----> fahr : %.2f\n",celsius, fahr);
	return 0;
	}
