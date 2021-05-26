#include <stdio.h>

int stack[100];
int tos; // 전역공간에 들어가는 변수는 초기화가 됨

void push(int data)
{
    stack[tos] = data;
    ++tos;

}

int pop(void) 
{
    --tos;
    return stack[tos];

}

int main(void) 
{
    push(100);
    push(200);
    push(300);

    printf("1st pop() : %d\n", pop());
    printf("1st pop() : %d\n", pop());
    printf("1st pop() : %d\n", pop());
    
    return 0;
}