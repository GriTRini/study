#include <iostream>
#include "complex.h"

int main(){
   Complex c1(3.0, 4.0);
   Complex c2 = 3.0;
   Complex c3;
   Complex c4 = c1;
   
   c2 = 3.0;
   c3 = c1 + c2;
   c3 = c2 = c1;
   
   ++c3;      // c3.operator++()
   c3++;      // c3.operator++(0)      // 0:dummy
   
   std::cout << "inpiut c2 and c3: ";
   std::cin >> c2 >> c3;      // ::operator >> (cin, c2)
   
   if(c1 == c2)
      std::cout << "c1 and c2 are equal" << std::endl;
   else
      std::cout << "c1 and c2 are not equal" << std::endl;
      
   //std::cout << "c1 : (" << c1.real() << ", " << c1.imag() << "i)" << std::endl;
   //std::cout << "c2 : (" << c2.real() << ", " << c2.imag() << "i)" << std::endl;
   //std::cout << "c3 : (" << c3.real() << ", " << c3.imag() << "i)" << std::endl;
   //std::cout << "c4 : (" << c4.real() << ", " << c4.imag() << "i)" << std::endl;
   std::cout << "c1 : " << c1 << std::endl;
   std::cout << "c2 : " << c2 << std::endl;
   std::cout << "c3 : " << c3 << std::endl;
   std::cout << "c4 : " << c4 << std::endl;
   
   const Complex c5(3.0, 4.0);
   
   std::cout << "c5 : (" << c5.real() << ", " << c5.imag() << "i)" << std::endl;
   
   return 0;
}
