#include <stdio.h>

int factorial(int base)
{
	int result = 1;
	for(int i = 2; i <= base; ++i) {
		result *= i;
		printf("%d\n", i);
	}
	
	return result;
}



int main(void)
{
	for (int i = 1; i <= 100; ++i) {
		int result;
		result = factorial(i);
	
		//printf("%d! = %d\n", i, result);
	}
	return 0;
}
