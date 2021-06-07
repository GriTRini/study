//
// Created by user on 2021-06-07.
//
#include <vector>
#include <iostream>
#include <algorithm>
#include "student_info.h"
#include "grade.h"

using namespace std;

int main()
{
    vector<Student_info> students;

    Student_info s;
    while(s.read(cin)) {
        students.push_back(s);
    }

    sort(students.begin(), students.end(), ::compare);

    vector<Student_info>::const_iterator iter;
    for (iter = students.cbegin(); iter != students.cend(); ++iter) {
        cout << iter->name() << " : " << iter->grade() << endl;
    }

    return 0;
}