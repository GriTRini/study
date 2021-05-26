#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

static int queue[100];
static int front;
static int rear;

void initQueue(Queue *pq)
{
	pq->rear = 0;
}

void push(Queue *pq, int data)
{
	if (pq->rear == QUEUESIZE) {
		fprintf(stderr, "queue is full\n");
	}
	
	pq->array[pq->rear] = data;
	++pq->rear;
}
/*
void push(int data)
{
	queue[rear] = data;
	++rear;
}
*/

int pop(Queue *pq)
{
	if (pq->rear == 0) {
		fprintf(stderr, "queue is empty\n");
		exit(2);
	}
	int tmp = pq->front;
	++pq->front;
	return pq->array[tmp];
}
/*
int pop(void)
{
	int tmp = front;
	++front;
	
	return queue[tmp];
	
	//return queue[front++];
}
*/
