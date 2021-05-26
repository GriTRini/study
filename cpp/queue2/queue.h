#ifndef QUEUE_H
#define QUEUE_H
#define QUEUESIZE 10
#include <iostream>

class Queue {
friend std::ostream& operator<<(std::ostream& out, const Queue& rhs);
private:
	int *pArr_;
	int size_;
	int rear_;
	int front_;

	Queue (const Queue& rhs);
	
	Queue& operator=(const Queue& rhs);
	
public:
	explicit Queue(int size = QUEUESIZE);
	~Queue();
	
	int size() const;
	
	bool empty() const;
	bool full() const;
	
	void push(int data);
	int pop();
};

#endif
