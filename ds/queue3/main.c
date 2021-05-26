#include <stdio.h>
#include "queue.h"


int main(void)
{
	Queue q1, q2;
	
	initQueue(&q1);
	initQueue(&q2);
	
	push(&q1, 100);
	push(&q1, 200);
	
	
	printf("1st pop() : %d\n", pop(&q1));
	
	push(&q1, 300);
	
	printf("2nd pop() : %d\n", pop(&q1));
	printf("3rd pop() : %d\n", pop(&q1));

	return 0;
}
