#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using namespace std;

int main()
{   cout << "please enter your name :";
    string name;
    cin >> name;

    cout << "hello, " + name << endl;

    cout << "plese enter your midterm finalterm score :";
    int midterm, finalterm; 
    cin >> midterm >> finalterm;

    int count = 0;
    int sum = 0;

    int hw;

    while (cin >> hw) {
        ++count;
        sum += hw;
    }
    std::streamsize prec = cout.precision();
    cout << std::setprecision(3);       // 소수점 3번째 자리 까지 출력
    cout << "Your final score :" << 0.2 * midterm + 0.4 * finalterm + 0.4 * sum << endl;
    cout << std::setprecision(prec);

    return 0;
}