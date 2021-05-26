#include "queue.h"
#include <cassert>

std::ostream& operator<<(std::ostream& out, const Queue& rhs)
{
	out << "[";
	for(int i = rhs.front_; i < rhs.rear_; ++i) {
		out << rhs.pArr_[i] ;
		out << ((i + 1 != rhs.rear_ ) ? ", " : "");
	}
	out << "]" << std::endl;
	
	out << "rear : " << rhs.rear_<< std::endl;
	out << "front : " << rhs.front_ << std::endl;
}

Queue::Queue(int size)
{
	pArr_= new int[size];
	assert(pArr_);
	
	size_= size;
	front_= 0;
	rear_= 0;
}

Queue::~Queue()
{
	delete[] pArr_;
}

void Queue::push(int data)
{
	assert(rear_!= size_);
	
	pArr_[rear_] = data;
	++rear_;
}

int Queue::size() const
{
	return size_;
}

int Queue::pop()
{
	assert(rear_);
	
	
	return pArr_[front_++];
}

bool Queue::empty() const
{
	return front_ == rear_;
}

bool Queue::full() const
{
	return rear_ == QUEUESIZE;
}
