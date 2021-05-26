#include <iostream>
#include "queue.h"


int main()
{
	Queue q1(10);
	Queue q2(100);
	
	q1.push(100);
	q1.push(200);
	q1.push(300);
	
	std::cout << "1st pop() : " << q1.pop() << std::endl;
	std::cout << "2nd pop() : " << q1.pop() << std::endl;
	std::cout << "3rd pop() : " << q1.pop() << std::endl;
	
	q2.push(900);
	q2.push(800);
	q2.push(700);
	
	std::cout << "1st pop() : " << q2.pop() << std::endl;
	std::cout << "2nd pop() : " << q2.pop() << std::endl;
	std::cout << "3rd pop() : " << q2.pop() << std::endl;


	return 0;
}
