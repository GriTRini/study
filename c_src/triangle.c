#include <stdio.h>

int main(void){

	int width, height;
	
	printf("input width, height :");
	scanf("%d %d" , &width, &height);
	
	double area;
	area = 0.5 * width * height;
	
	printf("area = %.2f\n" , area);
	return 0;
} 
