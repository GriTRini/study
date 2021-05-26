#include <stdio.h>

int sumArray ( int pArr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; ++i) {
		sum += pArr[i];
	}
	
	return 0;
}

int main(void)
{
	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	
	int sum;
	//sum = sumArray(nums, 10);
	sum = sumArray(nums + 5, 5);
	
	printf("sum : %d\n", sum);
		
	return 0;
}
