//
// Created by user on 2021-06-01.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <string>

using namespace std;

struct Student_info 
{
    string name;
    double midterm;
    double finalterm;
    vector<double> homework;
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

double grade(const Student_info& s) 
{
    return grade(s.midterm, s.finalterm, s.homework);
}

istream& read_hw(istream& in, vector<double>& homework) 
{
    if (in ) {
        homework.clear();
        double x;

        while (in >> x)
            homework.push_back(x);

        in.clear();
    }

    return in;
}

istream& read(istream& in, Student_info& s) 
{
    in >> s.name >> s.midterm >> s.finalterm;
    read_hw(in, s.homework);
    return in;
}

bool compare(const Student_info& s1, const Student_info& s2) 
{
    return s1.name < s2.name;
}

// 60밑은 과락
bool fgrade(const Student_info& s) 
{
    return ::grade(s) < 60;
}

/*
vector<Student_info> extract_fails(vector<Student_info>& students) 
{
    vector<Student_info> pass, fail;

    for (vector<Student_info>::size_type i = 0; i != students.size() ; ++i) {
        if (::fgrade(students[i]))
            fail.push_back(students[i]);
        else
            pass.push_back(students[i]);
    }
    students = pass;

    return fail;
}

vector<Student_info> extract_fails(vector<Student_info>& students) 
{
    vector<Student_info> fail;

    vector<Student_info>::size_type i = 0;
    while (i != students.size()) {
        if (fgrade(students[i])) {
            fail.push_back(students[i]);
            students.erase(students.begin() + i);
        }else {
            ++i;
        }
    }
    return fail;
}
*/

vector<Student_info> extract_fails(vector<Student_info>& students) 
{
    vector<Student_info> fail;
    //iter는 vector<Student_info>::iterator의 타입이다.
    typedef vector<Student_info>::iterator vec_iter;
    // iter를 students.begin()으로 값을 할당한 후에 iter가 end와 같지 않을때까지 증가시킨다.
    for (vec_iter iter = students.begin(); iter != students.end(); ++iter) {        
        // iter가 나타내는 값을 포인터로 가르켜서 가지고 온다.
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            students.erase(iter);       // iter 초기화
        } else {
            ++iter;
        }
    }
    return fail;
}

int main() {
    vector<Student_info> students;

//    int maxLen = 0;
    string::size_type maxLen = 0;
    Student_info record;
    while (read(cin, record)) {
        students.push_back(record);
        maxLen = max(maxLen, record.name.size());
    }

    sort(students.begin(), students.end(), compare);

    const vector<Student_info> fails = extract_fails(students);

    cout << "pass list" << endl;
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        cout << students[i].name << string(maxLen - students[i].name.size() + 1, ' ');
        try {
            std::streamsize prec = cout.precision();
            cout << std::setprecision(3);
            cout << "Your final score : " << grade(students[i]) << endl;
            cout << std::setprecision(prec);
        } catch (domain_error& e) {
            cerr << e.what() << endl;
            return 1;
        }
    }

    cout << endl << "fail list" << endl;
    typedef vector<Student_info>::const_iterator vect_citer;    // Read only
    for (vect_citer iter = fails.begin(); iter != fails.end(); ++iter) {
        cout << iter->name << string(maxLen - iter->name.size() + 1, ' ');
        try {
            std::streamsize prec = cout.precision();
            cout << std::setprecision(3);
            cout << "Your final score : " << grade(*iter) << endl;
            cout << std::setprecision(prec);
        } catch (domain_error& e) {
            cerr << e.what() << endl;
            return 1;
        }
    }

    return 0;
}