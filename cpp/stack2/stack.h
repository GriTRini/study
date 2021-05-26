#ifndef STACK_H
#define STACK_H
#define STACKSIZE 10
#include <iostream>

class Stack {
friend std::ostream& operator<<(std::ostream& out, const Stack& rhs);
private:
	int *pArr_;
	int size_;
	int tos_;
	
	Stack (const Stack& rhs); // if not use // Stack (const Stack& rhs) { // member copy!}
	
	Stack& operator=(const Stack& rhs); // if not use // Stack& operator=(const Stack& rhs) { // memver copy}
	
public:
	explicit Stack(int size = STACKSIZE); // Stack() {}
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
