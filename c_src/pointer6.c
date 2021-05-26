#include <stdio.h>

int main(void)
{
	void *p;
	int a = 100;
	
	p = &a;
	*(int *)p = 200;
	
	double d;
	d = 3.14;
	p = &d;
	*(double*)p = 2.718;
	
	printf("a: %d\td: %f\n", a, d);
	return 0;
}
