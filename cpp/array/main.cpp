#include <iostream>
#include "array.h"

int main()
{
	int nums[] = {1, 2, 3, 4, 5};
	Array arr1(nums, 5);
	Array arr2(100);			// Array arr2 = 100 ??? explicit
	Array arr3;
	Array arr4 = arr1;
	
	arr3 = arr1;
	
	if (arr3 == arr1) {
		std::cout << "arr1 and arr3 are equal" << std::endl;
	} else {
		std::cout << "arr1 and arr3 are not equal" << std::endl;
	}
	
	for(int i = 0; i < arr1.size(); ++i) {
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	
	const Array arr5 = arr1;
	for(int i = 0; i < arr5.size(); ++i) {
		std::cout << arr5[i] << " ";
	}
	std::cout << std::endl;
	
	return 0;
}
