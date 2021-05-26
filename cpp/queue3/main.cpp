#include <iostream>
#include "queue.h"


int main()
{
	Queue q1(10);
	Queue q2(100);
	
	q1.push(100);
	q1.push(200);
	q1.push(300);
	
	while ( !q1.empty()) {
		std::cout << "q1.pop() : " << q1.pop() << std::endl;
	}
	
	q2.push(900);
	q2.push(800);
	q2.push(700);
	
	while ( !q2.empty()) {
		std::cout << "q2.pop() : " << q2.pop() << std::endl;
	}


	return 0;
}
