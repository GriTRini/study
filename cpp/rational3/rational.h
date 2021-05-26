#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational{
friend std::istream& operator>>(std::istream& in, Rational& rhs);
friend std::ostream& operator<<(std::ostream& out, const Rational& rhs);
private:
	int up;
	int dw;
	
public:
	Rational(int up, int dw = 1);
	Rational(const Rational& rhs);
	~Rational();
	
	Rational& operator=(const Rational& rhs);
	bool operator == (const Rational& rhs) const;
	const Rational operator + (const Rational& rhs) const;

	Rational& operator++();
	Rational operator++(int );	
	
	int upper(void) const;
	int down(void) const;
	
};

#endif

