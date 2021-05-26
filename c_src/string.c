#include <stdio.h>

int main(void)
{
	//char str[] = {'h','e','l','l','o','\0');
	char str[] = "hello, world";

	printf("str + 7: %s\n", str + 7);
	
	char str2[13];
	int i;
	for (i = 0; str[i] != '\0' ; ++i) {
		str2[i] = str[i];
	}
	str2[i] = '\0';
	
	printf("str2 : %s\n", str2 );
	for (i = 0; str[i] ; ++i) {
		if (str[i] != str2[i]) 
			break;
	}
	
	if (str[i] == '\0') {
		printf("equal\n");
	} else {
		printf("not equal\n");
	}    // if(&str[0] == &str2[0])
	
	return 0;
}
