#include <stdio.h>

int sumArray(int nums[])
{
	int sum;
	
	for ( int i = 0; i < sizeof(nums) / sizeof(nums[0]); ++i) {
		sum = sum + nums[i];
	}
	return sum;
	
}

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	int sum;
	
	printf("sum : %d\n", sum);
		
	return 0;
}
