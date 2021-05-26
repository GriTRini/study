#include <stdio.h>
#include "queue.h"

int main(void)
{
	Queue q1, q2;
	
	initQueue(&q1, 100);
	initQueue(&q2, 10);
	
	push(&q1, 100);
	push(&q1, 200);
	push(&q1, 300);
	
	printf("1st pop() : %d\n", pop(&q1));
	printf("2nd pop() : %d\n", pop(&q1));
	printf("3rd pop() : %d\n", pop(&q1));
	
	push(&q2, 900);
	push(&q2, 800);
	push(&q2, 700);
	
	printf("1 pop : %d\n", pop(&q2));
	printf("2 pop : %d\n", pop(&q2));
	printf("3 pop : %d\n", pop(&q2));
	
	pop(&q1);
	
	cleanupQueue(&q1);
	cleanupQueue(&q2);

	return 0;
}
