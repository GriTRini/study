#include "queue.h"
#include <cassert>
#include "array.h"
const int Queue::QUEUE_SIZE = 10;

std::ostream& operator<<(std::ostream& out, const Queue& rhs)
{
	out << "[";
	for(int i = rhs.front_; i < rhs.rear_; ++i) {
		out << rhs.arr_[i] ;
		out << ((i + 1 != rhs.rear_ ) ? ", " : "");
	}
	out << "]" << std::endl;
	
	out << "rear : " << rhs.rear_<< std::endl;
	out << "front : " << rhs.front_ << std::endl;
}

Queue::Queue(int size)
: arr_(size), front_(0), rear_(0)
{

}

Queue::~Queue()
{

}

void Queue::push(int data)
{
	
	arr_[rear_] = data;
	++rear_;
}

int Queue::size() const
{
	return arr_.size();
}

int Queue::pop()
{
	assert(rear_);
	
	
	return arr_[front_++];
}

bool Queue::empty() const
{
	return front_ == rear_;
}

bool Queue::full() const
{
	return rear_ == Queue::QUEUE_SIZE;
}
