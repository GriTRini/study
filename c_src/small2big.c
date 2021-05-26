#include <stdio.h>

int main(void)
{
	char ch;
	printf("input small char :");
	scanf("%c", &ch);
	
	if(ch >= 'a' && ch <= 'z') {
		ch = ch - 'a' + 'A';
	}
	
	printf("big char : %c\n", ch);
	return 0;
}
