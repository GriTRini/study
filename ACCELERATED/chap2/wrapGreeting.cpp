#include <iostream>
#include <string>

int main()
{
    std::cout << "please enter your first name :";
    std::string name;
    std::cin >> name;

    std::string greeting = "Hello, " + name + "!";
    std::string space(greeting.size(), ' ');
    std::string secondLine = "* " + space + " *";
    std::string firstLine(secondLine.size(), '*');

    std::cout << firstLine << std::endl;
    std::cout << secondLine << std::endl;    
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << secondLine << std::endl;
    std::cout << firstLine << std::endl;
    
    return 0;

}