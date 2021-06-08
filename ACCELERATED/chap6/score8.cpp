

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <string>
#include <numeric>

using namespace std;

struct Student_info 
{
    string name;
    double midterm;
    double finalterm;
    vector<double> homework;
};

typedef vector<Student_info> container;

double average(const vector<double>& vec) 
{
    // accumulate = <numeric> (첫 2개의 인수 범위 값들을 더하며 세 번째 인수로 주어진값을 합하는 과정을 시작)
    // 마지막에 0.0인 이유는 타입이 double이기 때문이다.
    return accumulate(vec.cbegin(), vec.cend(), 0.0) / vec.size();
}

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

double grade_aux(const Student_info& s) 
{
    try {
        return grade(s);
    }
    catch (domain_error) {
        return grade(s.midterm, s.finalterm, 0);
    }
}

double average_grade(const Student_info& s) 
{
    return grade(s.midterm, s.finalterm, average(s.homework));
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

//60점 미만은 과락
bool fgrade(const Student_info& s) 
{
    return ::grade(s) < 60;
}

// 과락이아닌 애들만 return
bool pgrade(const Student_info& s) 
{
    return !::grade(s);
}

//container extract_fails(container& students)
//{
//    container fail;
//
//    // 과락 학생들의 정보를 fail 벡터로 복사, 조건을 판별하려고 값 대신 서술 함수를 네 번째 인수로 전달
//    // 서술함수를 만족하는 각 요소를 제거하므로 과락이 아닌 애들은 제거가 되고 과락인 애들은 fail 벡터에 복사
//    // 제거라는 말은 원래 값을 제거한다는 것이 아니라 그 값만 빼고 복사가 된다는 의미이다.
//    remove_copy_if(students.cbegin(), students.cend(), back_inserter(fail), pgrade);
//
//    //
//    students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());
//
//    return fail;
//}

container extract_fails(container& students)
{
    // partition 함수는 요소들을 카테고리로 구분하여 재배치 하고
    // stable_partiton 함수는 각 카테고리 안에서 요소 순서를 유지하면서 재배치 합니다.
    container::const_iterator iter = stable_partition(students.begin(), students.end(), pgrade);

    container fail(iter, students.cend());
    students.erase(iter, students.end());

    return fail;
}

//container extract_fails(container& students) 
// {
//    container fail;
//
//
//
//    typedef container::iterator container_iter;
//    for(container_iter iter = students.begin(); iter != students.end(); ) {
//        if (fgrade(*iter)) {
//            fail.push_back(*iter);
//            iter = students.erase(iter);
//        } else
//            ++iter;
//    }
//
//    return fail;
//}

// s.homework 벡터에 저장된 값 중 0이 있는지 확인한다.
bool did_all_hw(const Student_info& s) 
{
    // find함수의 반환값과 homework.cend() 함수의 반환 값을 비교하여 해당 학생이 모든 과제를 제출 했는지 확인
    // find함수는 찾으려는 값을 발견하지 못했을 때 두 번째 인수를 반환
    return find(s.homework.cbegin(), s.homework.cend(), 0) == s.homework.cend();
}

double median_analysis(const container& students) 
{
    vector<double> grades;
    // transform함수 첫 2개의 반복자는 최종 점수를 계산할 학생 정보의 범위를 지정, 세번째 반복자는 핵생들의 죄종 점수를 저장할 위치
    // 네번째 인수는 transform 함수가 전달받은 첫 2개의 반복자가 나타내는 범위의 요소들이 세번째 반복자가 나타내는 위치에 저장되기전
    // 거쳐야할 함수이다.
    // 4번째 인수의 grade는 오버로딩이 되어 있어서 그냥 grade만 적게 되면 어떤것을 불러야 하는지 모른다.
    // 그래서 grade_aux라는 함수를 만들어서 자신이 원하는 grade 함수를 불러오면 된다.
    transform(students.cbegin(), students.cend(), back_inserter(grades), grade_aux);

    return median(grades);
}

double median_average(const container& students) 
{
    vector<double> grades;
    transform(students.cbegin(), students.cend(), back_inserter(grades), average_grade);

    return median(grades);
}

// 반환타입은 void, 함수를 매개변수로 정의한다.
void write_analysis(ostream& out, const string& name, double (*analysis)(const container&),
                    const container& did, const container& didnt)
{
    out << name << " : median(did) = " << analysis(did) << ", median(didnt) = " << analysis(didnt) << endl;
}

int main() {
    container did, didnt;

//    int maxLen = 0;
    string::size_type maxLen = 0;

    Student_info record;

    //학생 정보를 읽고 과제를 모두 제출한 학생과 그렇지 않은 학생을 분류
    while (read(cin, record)) {
        if (did_all_hw(record))
            did.push_back(record);
        else
            didnt.push_back(record);
    }

    // 두 집단에 데이터가 있는지 각각 확인
    // empty함수는 해당 컨테이너가 비어있으면 참 그렇지 않으면 거짓
    if (did.empty()) {
        cout << "no Student did all the homework" << endl;
        return 1;
    }

    if (didnt.empty()) {
        cout << "every student did all the homework" << endl;
        return 1;
    }

    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", median_average, did, didnt);

    return 0;
}