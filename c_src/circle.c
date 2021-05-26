#include <stdio.h>

#define pi 3.141592

int main(void){

	int Radius;
	
	scanf("%d" , &Radius);
	
	double area;
	
	area = Radius*Radius*pi;
	
	printf("area = %.2f\n", area);
	return 0;
}
