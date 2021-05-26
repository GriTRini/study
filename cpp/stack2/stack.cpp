#include "stack.h"
#include <cassert>

std::ostream& operator<<(std::ostream& out, const Stack& rhs)
{
	out << "[";
	for(int i = 0; i < rhs.tos_; ++i) {
		out << rhs.pArr_[i] << ", ";
		out << ((i + 1 != rhs.tos_) ? ", " : "");
	}
	out << "]" << std::endl;
	
	out << "size : " << rhs.size_<< std::endl;
	out << "tos : " << rhs.tos_ << std::endl;
}

Stack::Stack(int size)
: pArr_(new int [size]), size_(size), tos_(0)
{
	//pArr_= new int[size];
	assert(this->pArr_);
	//size_= size;
	//tos_=0;
}

Stack::~Stack()
{
	delete [] pArr_;
}

int Stack::size() const
{
	return size_;
}
	
bool Stack::empty() const
{
	return tos_== 0;
}

bool Stack::full() const
{
	return tos_==STACKSIZE;
}
	
void Stack::push(int data)
{
	pArr_[tos_] = data;
	++tos_;
}

int Stack::pop()
{
	--tos_;
	return pArr_[tos_];
}
