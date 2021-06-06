#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{   cout << "please enter your name :";
    string name;
    cin >> name;

    cout << "hello, " + name << endl;

    cout << "plese enter your midterm finalterm score :";
    int midterm, finalterm;
    cin >> midterm >> finalterm;

    cout << "plese enter your homework score : ";
    vector<double> homework;    // vector<인자> 이름

    //hw를 double 로 선언한 후에 cin으로 입력한 후에 push_back으로 vector  homework에 넣음
    double hw;  
    while (cin >> hw) {
        homework.push_back(hw);
    }

    // homework size 확인
    if (homework.size() == 0) {
        cout << "you must enter you're grades please try again" << endl;
        return 1;
    }

    // <algorithm> 오름차순으로 정렬(default), 배열의 첫번째 ~ 마지막
    sort(homework.begin(), homework.end());

    double mid;
    if(homework.size() % 2 == 1) {      // size가 홀수이면
        mid = homework[homework.size() / 2];    //중간값은 homework의 size에서 2를 나눈 위치
    } else {                            // size가 짝수이면
        mid = (homework[homework.size() / 2 ] + homework[homework.size() / 2 - 1])/2;
        // 짝수이면 2로 나눈 위치와 1을 뺀 위치를 더하고 2로 나누면 중간값 (0으로 시작하기 때문에 1을 빼야함)
    }
     

    std::streamsize prec = cout.precision();
    cout << std::setprecision(3);
    cout << "Your final score :" << 0.2 * midterm + 0.4 * finalterm + 0.4 * mid << endl;
    cout << std::setprecision(prec);

    return 0;
}