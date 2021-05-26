#include <iostream>
#include "queue.h"
#include "complex.h"


int main()
{
	Queue<int> q1(10);
	
	q1.push(100);
	q1.push(200);
	q1.push(300);
	
	while ( !q1.empty()) {
		std::cout << "q1.pop() : " << q1.pop() << std::endl;
	}
	Queue<Complex> q2(100);
	q2.push(Complex(3, 4));
	q2.push(Complex(4, 5));
	q2.push(Complex(5, 6));
	
	while ( !q2.empty()) {
		std::cout << "q2.pop() : " << q2.pop() << std::endl;
	}


	return 0;
}
