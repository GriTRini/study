#ifndef SHAPE_H
#define SHAPE_H

class Shape{
protected:
	int x_;
	int y_;

public:
	Shape(int x, int y);
	// Shape(const Shape& rhs);
	virtual ~Shape() {  }
	// Shape& operator=(const Shape& rhs);
	// Shape *operator&() {return this;}
	// const Shape *operator&() const {return this; }
	
	void move(int x, int y);
	virtual double area() const = 0; // 함수를 정의할수 없다. 나를 상속하는 함수에서 알아서 사용해라, 순수 가상함수
											// 모든 모양의 넓이는 도형마다 다르기 때문에 정의할 수가 없음.

};

#endif
