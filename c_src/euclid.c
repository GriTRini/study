#include <stdio.h>

int main(void) 
{
	int a, b, num, den;
	scanf("%d %d", &a, &b);
	
	if(a>b) {
		num = a;
		den = b;
	}else {
		den = a;
		num = b;
	}

	int remain;
	while (remain = num % den) {
		num = den;
		den = remain;
	}
	
	printf("gcd : %d\n", den);
	return 0;
	
}
