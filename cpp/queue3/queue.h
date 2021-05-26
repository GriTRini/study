#ifndef QUEUE_H
#define QUEUE_H
//#define QUEUESIZE 10
#include <iostream>
#include "array.h"

class Queue {
friend std::ostream& operator<<(std::ostream& out, const Queue& rhs);
private:
	static const int QUEUE_SIZE;
	//int *pArr_;
	//int size_;
	Array arr_;
	int rear_;
	int front_;

	Queue (const Queue& rhs);
	
	Queue& operator=(const Queue& rhs);
	
public:
	explicit Queue(int size = Queue::QUEUE_SIZE);
	~Queue();
	
	int size() const;
	
	bool empty() const;
	bool full() const;
	
	void push(int data);
	int pop();
};

#endif
