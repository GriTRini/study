#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void initQueue(Queue *pq, int size, int eleSize)
{
	(*pq).pArr = malloc(eleSize + size);
   assert((*pq).pArr );
   
   (*pq).eleSize = eleSize;
   (*pq).size = size;
   (*pq).front = 0;
   	(*pq).rear = 0;
}

void cleanupQueue(Queue *pq)
{
	 free((*pq).pArr);
}

void push(Queue *pq, const void* pData)
{
 	assert((*pq).rear != (*pq).size);
   

   memcpy( (unsigned char *)(*pq).pArr + (*pq).rear*(*pq).eleSize, pData, (*pq).eleSize);
   
   ++(*pq).rear;
}
/*
void push(int data)
{
	queue[rear] = data;
	++rear;
}
*/

int pop(Queue *pq, void* pData)
{
	 assert((*pq).rear != 0);
	
	
   memcpy(pData, (unsigned char *)(*pq).pArr + (*pq).front*(*pq).eleSize, (*pq).eleSize);
   ++(*pq).front;
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
