#include "array.h"
#include <cassert>

const int Array::ARRAY_SIZE = 10;  // define과 다르게 타입을 확인한다.

Array::Array(int size)
: pArr_(new int[size]), size_(size)
{
	assert(pArr_);
}

Array::Array(const Array& rhs)
: pArr_(new int[rhs.size_]), size_(rhs.size_)
{
	assert(pArr_);
	
	for (int i = 0; i < rhs.size_; ++i) {
		pArr_[i] = rhs.pArr_[i];
	}		
}

Array::Array(const int *pArr, int size)
: pArr_(new int[size]), size_(size)
{
	assert(pArr_);
	
	for(int i = 0; i < size; ++i) {
		pArr_[i] = pArr[i];
	}
}

Array::~Array()
{
	delete [] pArr_;
}
	
Array& Array::operator=(const Array& rhs)
{
	if(this != &rhs) {
		delete [] pArr_;
		pArr_= new int[rhs.size_];
		assert(pArr_);
		size_ = rhs.size_;
	
		for(int i = 0; i < rhs.size_; ++i) {
			pArr_[i] = rhs.pArr_[i];
		}
	
	}
}
	
bool Array::operator==(const Array& rhs) const
{
	if (size_ != rhs.size_) {
		return false;
	}
	int i;
	for (i = 0; i < rhs.size_; ++i) {
		if(pArr_[i] != rhs.pArr_[i]) {
			break;
		}
	}
	
	if (i == rhs.size_) {
		return true;
	}else {
		return false;
	}
}
	
int& Array::operator[](int index)
{
	return pArr_[index];
}

const int& Array::operator[](int index) const
{
	return pArr_[index];
}

int Array::size() const
{
	return size_;
}
	
