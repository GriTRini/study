#include <stdio.h>

int main(void)
{

	int i;
	int sum = 0;
	i = 0;
	
	while (i <= 10){
		sum = sum + i;
		
		++i;
	}
	
	printf(" 1 to 10 sum = %d\n", sum);
	return 0;
}
