#ifndef ARRAY_H
#define ARRAY_H
// #define ARRAY_SIZE 10

//extern const int ARRAY_SIZE; 	// define과 다르게 타입을 확인한다.  전역변수인데 클래스와 관련된 전역변수는 static으로 만들어서 넣어준다.
class Array {
private:
	static const int ARRAY_SIZE;
	int *pArr_;
	int size_;

public:
	explicit Array(int size = Array::ARRAY_SIZE);
	Array(const Array& rhs);
	Array(const int *pArr, int size);
	~Array();
	
	Array& operator=(const Array& rhs);
	
	bool operator==(const Array& rhs) const;
	
	int& operator[](int index);
	const int& operator[](int index) const;
	int size() const;
};


#endif
