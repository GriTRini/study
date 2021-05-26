#ifndef STACK_H
#define STACK_H
//#define STACKSIZE 10
#include <iostream>
#include "array.h"


class Stack {
friend std::ostream& operator<<(std::ostream& out, const Stack& rhs);
private:
	static const int STACK_SIZE;
//	int *pArr_;
//	int size_;
	Array arr_;
	int tos_;
	
	Stack (const Stack& rhs); // if not use // Stack (const Stack& rhs) { // member copy!}
	
	Stack& operator=(const Stack& rhs); // if not use // Stack& operator=(const Stack& rhs) { // memver copy}
	
public:
	explicit Stack(int size = Stack::STACK_SIZE); // Stack() {}
	~Stack(); // ~Stack() { }
	
	// Stack *operator&() { return this;}
	// const Stack *operator&() const (return this; }
	int size() const;
	
	bool empty() const;
	bool full() const;
	
	void push(int data);
	int pop();
};

#endif
