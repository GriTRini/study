#include <iostream>
#include "array.h"
#include "safeArray.h"

int main() 
{
    int nums[] = {1, 2, 3, 4, 5};
    Array arr1(nums, 5);

    SafeArray arr2(nums, 5);

    for(int i = 0; i < arr1.size(); ++i) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    
    for(int i = 0; i < arr2.size(); ++i) {
    	std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

	//arr2[-1] = 1;
	
	Array *pArr = new SafeArray(nums, 5); // 부모클래스 타입의 refrence는 자식 클래스 타입의 객체를 가르키거나 참조할 수 있다.
	
	(*pArr)[1] = 1; 	// (*pArr)[-1] == pArr->operator[](-1)  Array::operator[](-1) o SafeArray::operator[](-1) x
							// virtual --> 								Array:: operator[](-1) x SafeArray::operator[](-1) o
	delete pArr;
    return 0;
}
