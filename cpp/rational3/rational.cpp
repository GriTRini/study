#include "rational.h"
std::istream& operator>>(std::istream& in, Rational& rhs)
{
	int num = 0;
	int den = 1;

	in >> num;
	if (in.peek() == '/') {
		in.ignore();
		in >> den;
	}

	if (in ) rhs = Rational(num, den);

	return in;

}
std::ostream& operator<<(std::ostream& out, const Rational& rhs)
{
	return out << rhs.up << "/" << rhs.dw ;
}

Rational::Rational(int up, int dw)
{
	this->up = up;
	this->dw = dw;
}
	
Rational::Rational(const Rational& rhs)
{
	this->up = rhs.up;
	this->dw = rhs.dw;
}

Rational::~Rational()
{

}

Rational& Rational::operator=(const Rational& rhs)
{
	this->up = rhs.up;
	this->dw = rhs.dw;
	
	return *this;
}

bool Rational::operator == (const Rational& rhs) const
{
	return (this->up == rhs.up && this->dw == rhs.dw);
}

const Rational Rational::operator + (const Rational& rhs) const
{
	return Rational(this->up * rhs.dw + this->dw * rhs.up, this->dw * rhs.dw);
}

Rational& Rational::operator++()
{
	this->up += this->dw; 
	return *this;
}

Rational Rational::operator++(int )
{
	Rational tmp(*this);
	this->operator++();
	
	return tmp;
}

int Rational::upper() const
{
	return this->up;
}

int Rational::down() const
{
	return this->dw;
}


