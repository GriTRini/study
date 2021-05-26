#include <iostream>
#include "rational.h"

int main()
{
	Rational r1(3,4);
	Rational r2(5);
	
	std::cout << "r1 = " << r1.upper() << "/" << r1.down() << std::endl;
	std::cout << "r2 = " << r2.upper() << "/" << r2.down() << std::endl;


	return 0;
}
