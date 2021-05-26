#include <stdio.h>

int main(void){

	int width, height;
	
	//scanf("%d", &height);
	//scanf("%d", &width);
	scanf("%d %d" , &height, &width);
	
	int area;
	area = width * height;
	
	printf("area = %d\n " , area);
	return 0;
}
