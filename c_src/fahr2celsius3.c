#include <stdio.h>

int main(void)
{

	int fahr;
	int celsius;
	int celsius1;
	
	fahr = 100;
	
	celsius = (fahr - 32) * 5 / 9 ;
	celsius1 = (((fahr - 32) * 5000 / 9) - (celsius * 1000 ) +
	 5)/10;
	printf("fahr: %d ---> celsius: %d.%d \n", fahr, celsius, celsius1);
	return 0;

}
