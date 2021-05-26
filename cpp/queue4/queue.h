#ifndef QUEUE_H
#define QUEUE_H
//#define QUEUESIZE 10
#include <iostream>
#include "safeArray.h"

template <typename T>
class Queue {
template <typename U>
friend std::ostream& operator<<(std::ostream& out, const Queue<U>& rhs);
private:
	static const int QUEUE_SIZE;
	//int *pArr_;
	//int size_;
	SafeArray<T> arr_;
	int rear_;
	int front_;

	Queue (const Queue<T>& rhs);
	
	Queue& operator=(const Queue<T>& rhs);
	
public:
	explicit Queue(int size = Queue<T>::QUEUE_SIZE);
	~Queue();
	
	int size() const;
	
	bool empty() const;
	bool full() const;
	
	void push(const T& data);
	const T& pop();
};

#include <cassert>

template <typename T>
const int Queue<T>::QUEUE_SIZE = 10;

template <typename T>
std::ostream& operator<<(std::ostream& out, const Queue<T>& rhs)
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

template <typename T>
Queue<T>::Queue(int size)
: arr_(size), front_(0), rear_(0)
{

}

template <typename T>
Queue<T>::~Queue()
{

}

template <typename T>
void Queue<T>::push(const T& data)
{
	
	arr_[rear_] = data;
	++rear_;
}

template <typename T>
int Queue<T>::size() const
{
	return arr_.size();
}

template <typename T>
const T& Queue<T>::pop()
{
	assert(rear_);
	
	
	return arr_[front_++];
}

template <typename T>
bool Queue<T>::empty() const
{
	return front_ == rear_;
}

template <typename T>
bool Queue<T>::full() const
{
	return rear_ == Queue::QUEUE_SIZE;
}

#endif
