
#include <cassert>
#include "safeArray.h"

const int SafeArray::SAFEARRAY_SIZE = 10;  // define과 다르게 타입을 확인한다.

SafeArray::SafeArray(int size)
: Array(size)
{

}

SafeArray::SafeArray(const int *pArr, int size)
: Array(pArr, size)
{

}

SafeArray::SafeArray(const SafeArray& rhs)
: Array( static_cast<Array> (rhs)) // Array만 잘라서 가져온다. 자식클래스 타입을 부모클래스 타입으로 바꿈
{
	
}

SafeArray::~SafeArray()
{

}

SafeArray& SafeArray::operator = (const SafeArray& rhs)
{
	this->Array::operator = ( static_cast<Array> (rhs));
	
	return *this;
}

bool SafeArray::operator==(const SafeArray& rhs) const
{
	return this->Array::operator==( static_cast<Array> (rhs));
}

int& SafeArray::operator[](int index)
{
	//assert(index >= 0 && index < this->Array::size());
	assert(index >= 0 && index < this->Array::size_)
	return this->Array::operator[](index);
}

const int& SafeArray::operator[](int index) const
{
	//assert(index >= 0 && index < this->Array::size());
	assert(index >= 0 && index < this->Array::size_)
	return this->Array::operator[](index);
}


