#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using namespace std;

struct Student_info {       // 구조체 Student_info
    string name;
    double midterm;
    double finalterm;
    vector<double> homework;
};

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

double grade(const Student_info& s) 
{
    // vector s의 midterm, fianlterm, homework에 해당하는 값을 return 한다.
    return grade(s.midterm, s.finalterm, s.homework);
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

istream& read(istream& in, Student_info& s)
{
    // vector s에 name, midterm, finalterm 을 cin으로 받는다.
    in >> s.name >> s.midterm >> s.finalterm;
    // vector s의 homework는 read_hw 함수로 받는다
    read_hw(in, s.homework);

}

bool compare(const Student_info& s1, const Student_info& s2)
{
    // 구조체 Student_info에 있는 s1과 s2의 이름을 비교해서 사전순으로 배열
    return s1.name < s2.name;
}

int main()
{   
    vector<Student_info> students;          // students의 벡터 선언
    
    //int maxLen = 0;
    string::size_type maxLen = 0;           // maxLen 선언

    Student_info record;
    while (read(cin, record)) {
        students.push_back(record);         // students 벡터에 들어가는 이름을 다음으로 넣기
        maxLen = max(maxLen, record.name.size());       // students 벡터에 들어가는 이름 사이즈를 비교하여 큰 값을 maxLen에 넣는다.
    }
    
    sort(students.begin(), students.end(), compare);        // compare 함수를 이용하여 이름을 나열한다.

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name << string(maxLen - students[i].name.size() + 1, ' ');
    
    
        try {
            std::streamsize prec = cout.precision();
            cout << std::setprecision(3);
            cout << grade(students[i]) << endl;
            cout << std::setprecision(prec);

        } catch (domain_error& e) {
            cerr << e.what() << endl;
            return 1;
        }
    }
         

    return 0;
}