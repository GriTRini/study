#include <stdio.h>

int main(void)
{
	int nums[] = {50, 90, 30, 10, 100, 20, 40, 60, 80, 70};
	
	int max = 0;
	
	int i;
	for (i = 0; i <10; ++i){
		if (max < nums[i]) {
		 max = nums[i];
			
		}
	}
	
	printf("max: %d\n", max);
	return 0;
}
