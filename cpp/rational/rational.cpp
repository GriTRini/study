#include "rational.h"
#include <cassert>

Rational::Rational(int up, int dw)
{
	assert(dw != 0);
	this->up = up;
	this->dw = dw;
}

Rational::Rational(int up)
{
	this->up = up;
	this->dw = 1;
}

Rational::~Rational()
{

}

int Rational::upper()
{
	return this-> up;
}

int Rational::down()
{
	return this-> dw;
}

void Rational::upper(int up)
{
	this->up = up;
}

void Rational::down(int dw)
{
	this->dw = dw;
}
