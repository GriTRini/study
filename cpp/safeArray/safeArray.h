#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include "array.h"
// #define ARRAY_SIZE 10

//extern const int ARRAY_SIZE; 	// define과 다르게 타입을 확인한다.  전역변수인데 클래스와 관련된 전역변수는 static으로 만들어서 넣어준다.
class SafeArray : public Array {  // 부모쪽에 있는 public이 자식쪽의 public으로 옮겨간다 부모 = Array, 자식 = SafeArray, public만 가능함 
private:							// public은 자식쪽에 있는 public에 들어갈 부모쪽의 private or public을 선택한다.
	static const int SAFEARRAY_SIZE;

public:
	explicit SafeArray(int size = SafeArray::SAFEARRAY_SIZE);
	SafeArray(const int *pArr, int size);
	SafeArray(const SafeArray& rhs);
	virtual ~SafeArray();					// 함수에 virtual 이 들어가면 소멸자에도 virtual이 붙어야 한다.

	SafeArray& operator=(const SafeArray& rhs);

	bool operator==(const SafeArray& rhs) const;

	virtual int& operator[](int index);
	virtual const int& operator[](int index) const;

};


#endif
