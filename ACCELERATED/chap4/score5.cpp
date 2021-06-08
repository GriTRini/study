#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Student_info {
    string name;
    double finalScore;
    // double midterm;
    // double finalterm;
    // vector<double> homework;
};

// 함수를 호출하면 인수로 제공된 벡터를 통째로 복사
double median(vector<double> vec)
{
    sort(vec.begin(), vec.end());       // 오름차순으로 정리

    const int mid = vec.size() / 2;     // vector로 선언한 vec의 사이즈를 2로 나누면 가운데 값이 됨

    return (vec.size() % 2 == 1) ? vec[mid] : (vec[mid] + vec[mid- 1]) / 2;     //짝수 또는 홀수 일때 가운데값 구하는 방법
        
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

/*
double grade( Student_info& s) 
{
    read()
    return grade(s.midterm, s.finalterm, s.homework);
}
*/

istream& read_hw(istream& in, vector<double>& homework)
{
    if (in) {
        
        homework.clear();
        double x;
        while(cin >> x) {
            homework.push_back(x);
        }
        in.clear();
    }

    return in;
}
/*
istream& read(istream& in, Student_info& s)
{
    in >> s.name >> s.midterm >> s.finalterm;
    read_hw(in, s.homework);

}
*/

istream& read(istream& in, Student_info& s)
{
    double midterm, finalterm;
    vector<double> homework;

    in >> s.name >> midterm >> finalterm;
    read_hw(in, homework);

    if(in) {
        s.finalScore = grade(midterm, finalterm, homework);
    }
    return in;
}

bool compare(const Student_info& s1, const Student_info& s2)
{
    return s1.name < s2.name;
}


int main()
{   
    vector<Student_info> students;

    vector<string>::size_type maxLen = 0;  // maxLen는 int 이고 students[i].name.size()는 string이여서 maxLen을 string으로 변환 
    Student_info record;
    while (read(cin, record)) {
        students.push_back(record);
        maxLen = max(maxLen, record.name.size());
    }

    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name << string(maxLen - students[i].name.size() + 1, ' ');
    
    
        try {
            std::streamsize prec = cout.precision();
            cout << std::setprecision(3);
            cout << students[i].finalScore << endl;
            cout << std::setprecision(prec);

        } catch (domain_error& e) {
            cerr << e.what() << endl;
            return 1;
        }
    }
         

    return 0;
}