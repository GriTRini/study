#include <stdio.h>
#include "string.h"

int main(void)
{
	char *str = "hello, world";
	
	int len = my_strlen(str);
	printf("len: %d\n", len);
	
	char str2[20];
	my_strcpy(str2, str);
	
	if(my_strcmp(str, str2) == 0) {
		printf("str and str2 are equal\n");
	} else {
		printf("str and str2 are not equal\n");
	
	}
	
	printf("str2 : %s\n", str2);
	
	my_strcat(str2, ", ");
	my_strcat(str2, "ros drone!");
	
	
	printf("str2 : %s\n", str2);
	return 0;
}
