#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "please enter your first name :";
    string name;    // name을 string으로 선언
    cin >> name;    // name을 cin으로 받음

    string greeting = "Hello, " + name + "!";   // cin으로 받은 name을 넣음
    string space(greeting.size(), ' ');         // space는 위에서 선언한 greeting의 size 만큼 ' '을 넣음
    string secondLine = "* " + space + " *";    // secondLine에서 *사이에 space를 넣음
    string firstLine(secondLine.size(), '*');   // firstLine에서는 secondLine의 size 만큼 별을 넣음

    cout << firstLine << endl;                 
    cout << secondLine << endl;    
    cout << "* " << greeting << " *" << endl;
    cout << secondLine << endl;
    cout << firstLine << endl;
    
    return 0;

}