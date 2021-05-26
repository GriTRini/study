#ifndef ARRAY_H
#define ARRAY_H
// #define ARRAY_SIZE 10

//extern const int ARRAY_SIZE; 	// define과 다르게 타입을 확인한다.  전역변수인데 클래스와 관련된 전역변수는 static으로 만들어서 넣어준다.
class Array {
private:
	static const int ARRAY_SIZE;
	int *pArr_;
	
protected:    	//자식쪽의 멤버 변수는 원래 private를 접근할 수 없다. 그래서 protected를 써서 자식 멤버가 부모쪽의 priate 멤버에 접근이 가능하다.
	int size_;

public:
	explicit Array(int size = Array::ARRAY_SIZE);
	Array(const Array& rhs);
	Array(const int *pArr, int size);
	virtual ~Array();
	
	Array& operator=(const Array& rhs);
	
	bool operator==(const Array& rhs) const;
	
	virtual int& operator[](int index);
	virtual const int& operator[](int dex) const;
	int size() const;
};


#endif
