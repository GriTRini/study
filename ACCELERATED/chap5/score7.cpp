//
// Created by user on 2021-06-01.
//

#include <iostream>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::max;
using std::list;
using std::string;
using std::istream;
using std::domain_error;
using std::streamsize;
using std::cerr;
using std::vector;

struct Student_info 
{
    string name;
    double midterm;
    double finalterm;
    vector<double> homework;
};

double median(vector<double>& vec) 
{
    sort(vec.begin(), vec.end());
    const int mid = vec.size() / 2;

//    if (vec.size() % 2 == 1)
//        return vec[mid];
//    else
//        return (vec[mid] + vec[mid -1]) / 2;

    return ((vec.size() % 2 == 1) ? vec[mid] : (vec[mid] + vec[mid -1]) / 2) ;
}

double grade(double midterm, double finalterm, double homework) 
{
    return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
}

double grade(double midterm, double finalterm, const vector<double>& homework) 
{
    if(homework.size() == 0)
        throw domain_error("student has done no homework");

    vector<double> tmp = homework;
    return grade(midterm, finalterm, median(tmp));
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

list<Student_info> extract_fails(list<Student_info>& students) 
{
    list<Student_info> fail;

    typedef list<Student_info>::iterator vec_iter;
    for (vec_iter iter = students.begin(); iter != students.end(); ++iter) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else {
            ++iter;
        }
    }
    return fail;
}

int main() {
    list<Student_info> students;

//    int maxLen = 0;
    string::size_type maxLen = 0;
    Student_info record;
    while (read(cin, record)) {
        students.push_back(record);
        maxLen = max(maxLen, record.name.size());
    }

    //sort(students.begin(), students.end(), compare);
    students.sort(compare);

    const list<Student_info> fails = extract_fails(students);

    cout << "pass list" << endl;
    typedef list<Student_info>::const_iterator list_citer;

    for (list<Student_info>::const_iterator iter = students.begin(); iter != students.end(); ++iter) {
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

    cout << endl << "fail list" << endl;
    
    for (list_citer iter = fails.begin(); iter != fails.end(); ++iter) {
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