#ifndef STACK_H
#define STACK_H
//#define STACKSIZE 100

class Stack{
private:
	//int array[STACKSIZE];
	int *pArr;
	int size;
	int tos;

public:
	Stack(int size);		//constructor
	~Stack();				//destructor

	void push(int data);
	int pop();
};




#endif
