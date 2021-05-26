#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
	srand(time(NULL));
	int buket[45];
	
	for (int i = 0; i < 45; ++i) {
		buket[i] = i +1;
	}
	
	for (int i = 1; i <= 1000000; ++i) {
		int num1 = rand() % 45 ;
		int num2 = rand() % 45 ;
		
		int temp = buket[num1];
		buket[num1] = buket[num2];
		buket[num2] = temp;
	}
	for (int i = 0; i < 7; ++i) {
		printf("%d ", buket[i]);
	}
	printf("\n");
	
	return 0;
}
