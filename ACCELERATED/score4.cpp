#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using std::sort;
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::setprecision;
using std::cerr;
using std::max;

struct Student_info {
    string name;
    double midterm;
    double finalterm;
    vector<double> homework;
};
double median(vector<double> vec)
{
    sort(vec.begin(), vec.end());

    const int mid = vec.size() / 2;

    return (vec.size() % 2 == 1) ? vec[mid] : (vec[mid] + vec[mid- 1]) / 2;
        
}
double grade(double midterm, double finalterm, double homework)
{
    return 0.2 * midterm + 0.4 *
     finalterm + 0.4 * homework;
}

double grade(double midterm, double finalterm, const vector<double>& homeworks)
{
    if (homeworks.size() == 0) {
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

istream& read(istream& in, Student_info& s)
{
    in >> s.name >> s.midterm >> s.finalterm;
    read_hw(in, s.homework);

}

bool compare(const Student_info& s1, const Student_info& s2)
{
    return s1.name < s2.name;
}
int main()
{   
    vector<Student_info> students;
    
    //int maxLen = 0;
    string::size_type maxLen = 0;

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
            cout << grade(students[i]) << endl;
            cout << std::setprecision(prec);

        } catch (domain_error& e) {
            cerr << e.what() << endl;
            return 1;
        }
    }
         

    return 0;
}