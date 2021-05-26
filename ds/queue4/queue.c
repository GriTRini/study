#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void initQueue(Queue *pq, int size)
{
	pq->pArr = malloc(sizeof(int) * size);
	assert(pq->pArr);
	
	pq->size = size;
	pq->front = 0;
	pq->rear = 0;
}

void cleanupQueue(Queue *pq)
{
	free(pq->pArr);
}

void push(Queue *pq, int data)
{
	assert(pq->rear != pq->size);
	
	pq->pArr[pq->rear] = data;
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
	assert(pq->rear != 0);
	
	
	return pq->pArr[pq->front++];
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
