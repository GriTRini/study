#include <stdio.h>

int main(void)
{
	int num;
	printf("input num: " );
	scanf("%d" , &num);
	
	int is0dd;
	is0dd = (num % 2 == 1);
	
	printf("%d is a odd number : %d\n", num, is0dd);
	return 0;
}
