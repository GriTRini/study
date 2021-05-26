#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void initStack(Stack *ps)
{
	ps->tos = 0;
}

void push(Stack *ps, int data)
{
	if (ps->tos == STACKSIZE) {
		fprintf(stderr, "stack is full\n");
	}
	
	ps->array[ps->tos] = data;
	++ps->tos;
}
/*
void push(int data)
{
    stack[tos] = data;
    ++tos;

}
*/
int pop(Stack *ps)
{
	if (ps->tos == 0) {
		fprintf(stderr, "stack is empty\n");
		exit(-2);
	}
	--ps->tos;
	return ps->array[ps->tos];
}
/*
int pop(void) 
{
    --tos;
    return stack[tos];

}
*/
