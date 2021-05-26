#include <stdio.h>

int main(void)
{

	int i;
	int sum;
	
	for(i=1; i<=10; ++i){
		sum = sum + i;
	}
	
	printf(" 1 to 10 sum = %d\n", sum);
	return 0;
}
