#include "complex.h"
/*
Complex::Complex()  // default
{
	this->re = 0.0;
	this->im = 0.0;
}

Complex::Complex(double re) // convert
{
	this->re = re;
	this->im = 0.0;
}
*/
Complex::Complex(double re, double im)
{
	this->re = re;
	this->im = im;
}

Complex::Complex(const Complex &rhs)
{
	this->re = rhs.re;
	this->im = rhs.im;
}

Complex::~Complex()
{

}

Complex& Complex::operator = (const Complex& rhs)
{
	this->re = rhs.re;
	this->im = rhs.im;
	
	return *this;
}

bool Complex::operator == (const Complex& rhs)
{
	return (this->re == rhs.re && this->im == rhs.im);
}

const Complex Complex::operator+(const Complex& rhs)
{
	Complex re(this->re + rhs.re, this->im + rhs.im);
	return re;
}

double Complex::real()
{
	return this->re;
}

double Complex::imag()
{
	return this->im;
}

void Complex::real(double re) 
{
	this->re = re;
}

void Complex::imag(double im)
{
	this->im = im;
}
