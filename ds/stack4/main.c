#include <stdio.h>
#include "stack.h"

int main(void)
{
	Stack s1, s2;
	
	initStack(&s1, 100);
	initStack(&s2, 10);
	
	push(&s1, 100);
	push(&s1, 200);
	push(&s1, 300);
	
	printf("1 pop : %d\n", pop(&s1));
	printf("2 pop : %d\n", pop(&s1));
	printf("3 pop : %d\n", pop(&s1));
	
	push(&s2, 900);
	push(&s2, 800);
	push(&s2, 700);
	
	printf("1 pop : %d\n", pop(&s2));
	printf("2 pop : %d\n", pop(&s2));
	printf("3 pop : %d\n", pop(&s2));
	
	pop(&s1);
	
	cleanupStack(&s1);
	cleanupStack(&s2);

	return 0;
	
}
