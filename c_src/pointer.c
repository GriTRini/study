#include <stdio.h>

int main(void)
{
	int a;
	int *p;
	
	a = 100;
	p = &a; //시작 주소값을 보여줌
	*p = 200; 
	
	printf("%d\n" ,a);
	return 0;
}	
