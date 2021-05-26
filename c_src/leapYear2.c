#include <stdio.h>

int main(void)
{
	int year;
	printf("input year : ");
	scanf("%d", &year);
/*
	if (year % 4 == 0 && year % 100 != 0 || year % 400 ==0 ){
		printf ("leapYear\n");
	} else {
		printf ("Not leapYear\n");
	}
*/

 	printf("%d is a %s Year\n", year, 
 	(	year % 4 == 0 && year % 100 != 0 || year % 400 ==0) ? "leap" : "Not leap");
	return 0;
} 
