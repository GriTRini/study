#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using namespace std;

// 함수를 호출하면 인수로 제공된 벡터를 통째로 복사
double median(vector<double> vec)   // vector vec 입력
{
    sort(vec.begin(), vec.end());   // 오름차순 정렬

    const int mid = vec.size() / 2; // 중간값은 vec.size를 2로 나눈 값

    // vec의 size가 홀수 이면 위에서 구한 mid와 mid-1을 더한후 2로 나눈값을 리턴한다.
    return (vec.size() % 2 == 1) ? vec[mid] : (vec[mid] + vec[mid- 1]) / 2;
        
}

double grade(double midterm, double finalterm, double homework) // midterm, finalterm, homework 입력
{
    return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
}

double grade(double midterm, double finalterm, const vector<double>& homeworks)
{
    if (homeworks.size() == 0) {
        // vector의 homeworks의 size가 0이면 밑의 문장 출력
        throw domain_error("student has done no homework");
    }
    return grade(midterm,  finalterm, median(homeworks));
}

istream& read_hw(istream& in, vector<double>& homework)
{
    if (in) {   // in이 0이 아니면
        
        homework.clear();   // vector homework를 clear함
        double x;
        while(cin >> x) {   // x를 double로 선언한 후에 vector homework에 넣음
            homework.push_back(x);
        }
        in.clear(); // in을 clear
    }

    return in;  //in을 retrun;
}

int main()
{   
    cout << "please enter your name :";
    string name;
    cin >> name;

    cout << "hello, " + name << endl;

    cout << "plese enter your midterm finalterm score :";
    int midterm, finalterm;
    cin >> midterm >> finalterm;

    cout << "plese enter your homework score : ";
    vector<double> homework;

    read_hw(cin, homework);
    
    try{
        std::streamsize prec = cout.precision();
        cout << std::setprecision(3);
        cout << "Your final score :" << grade(midterm, finalterm, homework) << endl;
        cout << std::setprecision(prec);

    } catch (domain_error& e) {
        cerr << "you must enter you're grades please try again" << endl;
        return 1;
    }

      

    return 0;
}