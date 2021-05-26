#include <stdio.h>
#include <string.h>

int main(void)
{
	char *str = "hello, world";
	
	int len = strlen(str);
	printf("len: %d\n", len);
	
	char str2[20];
	strcpy(str2, str);
	
	if(strcmp(str, str2) == 0) {
		printf("str and str2 are equal\n");
	} else {
		printf("str and str2 are not equal\n");
	
	}
	
	printf("str2 : %s\n", str2);
	
	strcat(str2, ", ");
	strcat(str2, "ros drone!");
	
	
	printf("str2 : %s\n", str2);
	return 0;
}
