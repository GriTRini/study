#include <iostream>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include<map>

using namespace std;

struct Student_info {
    string name;
    double midterm;
    double finalterm;
    vector<double> homework;
};

typedef vector<Student_info> container;
double median(vector<double>& vec)
{
    sort(vec.begin(), vec.end());
    
    const int mid = vec.size() / 2;
    return (vec.size() % 2 == 1) ? vec[mid] : (vec[mid] + vec[mid -1]) / 2;
}

double average(const vector<double>& vec)
{
    double sum;
    //for (vector<double>::const_iterator iter = vec.cbegin(); iter != vec.cend(); ++iter) {
    //    sun += *iter;
    //}
    double average = accumulate(vec.cbegin(), vec.cend(), 0.0) / vec.size();

    return average;
}

double grade(double midterm, double finalterm, double homework) 
{
    return 0.2 * midterm + 0.4 * finalterm + 0.4 * homework;
}

double grade(double midterm, double finalterm, const vector<double>& homework) 
{
    if (homework.size() == 0)
        throw domain_error("student has done no homework");

    vector<double> tmp = homework;
    return grade(midterm, finalterm, median(tmp));
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.finalterm, s.homework);
}

double grade_aux(const Student_info& s)
{
    try {
        return grade(s);
    } catch(domain_error &e) {
        return grade(s.midterm, s.finalterm, 0);
    }
}


istream& read_hw(istream& in, vector<double>& homework) {
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

bool pgrade(const Student_info& s)
{
    return !fgrade(s);
}
/*
vector<Student_info> extract_fails(vector<Student_info>& students) {
    vector<Student_info> fail;

    typedef vector<Student_info>::iterator vec_iter;
    for(vec_iter iter = students.begin(); iter != students.end(); ) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            students.erase(iter);
        } else
            ++iter;
    }

    return fail;
}
*/
/*
vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;

    remove_copy_if(students.cbegin(), students.cend(), back_inserter(fail), pgrade);
    
    students.erase remove_if(students.begin(), students,end(), fgrade), students.end()); 

    student.erase()
    return fail;
}
*/
container extract_fails(container& students)
{
    container::const_iterator iter
        = stable_partition(students.begin(), students.end(), pgrade);

    container fail(iter, students.cend());
    students.erase(iter, students.end());

    return fail;
}
bool did_all_hw(const Student_info& s)
{
    return find(s.homework.cbegin(), s.homework.cend(), 0) == s.homework.cend();
}

double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.cbegin(), students.cend(), back_inserter(grades), grade_aux);

    return median(grades);       
}

double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.cbegin(), students.cend(), back_inserter(grades), grade_aux);

    return average(grades);
}
void write_analysis(ostream& out, const string& name,
    double (*analysis)(const vector<Student_info>& ), const vector<Student_info>& did,
    const vector<Student_info>& didnt)
{
    out << name << ": median(did) " << analysis(did)
        << "median(didnt) : " << analysis(didnt);
}

int main()
{
    static char keys[] = {'F', 'F', 'F', 'F', 'F', 'F', 'D', 'C', 'B', 'A', 'A'};
    map<char, int> gradeCount;
    //gradeCount['D'] = 0;

    map<char, vector<string> > gradeNameMap;
     
    vector<Student_info> students;

    Student_info s;
    while (read(cin, s)) {
        students.push_back(s);
    }

    typedef vector<Student_info>::const_iterator vec_citer;
    for (vec_citer iter = students.cbegin(); iter != students.cend(); ++iter) {
        double score = grade(*iter);
       
       ++gradeCount[keys[static_cast<int>(score) / 10]];
        
        cout << iter->name << " : " << grade(*iter) << endl;
    }

    typedef map<char, int>::const_iterator map_citer;
    for (map_citer iter = gradeCount.cbegin(); iter != gradeCount.cend(); ++iter) {
        cout << iter->first << " : " << iter->second << endl;

    }
    return 0;
}