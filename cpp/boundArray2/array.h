#ifndef ARRAY_H
#define ARRAY_H
// #define ARRAY_SIZE 10

//extern const int ARRAY_SIZE; 	// define과 다르게 타입을 확인한다.  전역변수인데 클래스와 관련된 전역변수는 static으로 만들어서 넣어준다.
template <typename T>   // Template code 임의의 타입의 T를 받아서 c++ 코드를 만든다. 생성자 소멸자 클래스 이름은 그대로 (내부적으로 저장은 x)
class Array {				// Array를 Array<T>로 정수형 int는 T로 바꿈 
private:
	static const int ARRAY_SIZE;
	
	T *pArr_;
	
protected:
	int size_;

public:
	explicit Array(int size = Array<T>::ARRAY_SIZE);
	Array(const Array<T>& rhs);
	Array(const T *pArr, int size);
	~Array();
	
	Array<T>& operator=(const Array<T>& rhs);
	
	bool operator==(const Array<T>& rhs) const;
	
	virtual T& operator[](int index);				//int 형 reference를 T형 reference로 
	virtual const T& operator[](int dex) const;
	int size() const;
};

#include <cassert>

template <typename T>   // Template code 
const int Array<T>::ARRAY_SIZE = 10;  // define과 다르게 타입을 확인한다.

template <typename T>   // Template code 
Array<T>::Array(int size)
: pArr_(new T[size]), size_(size)
{
	assert(pArr_);
}

template <typename T>   // Template code 
Array<T>::Array(const Array<T>& rhs)
: pArr_(new T[rhs.size_]), size_(rhs.size_)
{
	assert(pArr_);
	
	for (int i = 0; i < rhs.size_; ++i) {
		pArr_[i] = rhs.pArr_[i];
	}		
}

template <typename T>   // Template code 
Array<T>::Array(const T *pArr, int size)
: pArr_(new T[size]), size_(size)
{
	assert(pArr_);
	
	for(int i = 0; i < size; ++i) {
		pArr_[i] = pArr[i];
	}
}

template <typename T>   // Template code 
Array<T>::~Array()
{
	delete [] pArr_;
}
	
template <typename T>   // Template code 
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if(this != &rhs) {
		delete [] pArr_;
		pArr_= new T[rhs.size_];
		assert(pArr_);
		size_ = rhs.size_;
	
		for(int i = 0; i < rhs.size_; ++i) {
			pArr_[i] = rhs.pArr_[i];
		}
	
	}
}

template <typename T>   // Template code 
bool Array<T>::operator==(const Array<T>& rhs) const
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
	
template <typename T>   // Template code 
T& Array<T>::operator[](int index)
{
	return pArr_[index];
}

template <typename T>   // Template code 
const T& Array<T>::operator[](int index) const
{
	return pArr_[index];
}

template <typename T>   // Template code s
int Array<T>::size() const
{
	return size_;
}
	

#endif
