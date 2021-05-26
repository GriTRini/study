#include <stdio.h>

int main(void)
{
	int num;
	printf("input num : ");
	scanf("%d", &num);
	
//	if (num % 2 ==0){
//		printf("even\n");
//	} else {
//		printf("odd\n");
//	}

	printf("%d is a %s\n", num, (num % 2 ) ? "odd" : "even");
	return 0;
}
