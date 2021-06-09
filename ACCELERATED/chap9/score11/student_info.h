//
// Created by user on 2021-06-07.
//
#ifndef ACCELERATED_STUDENT_INFO_H
#define ACCELERATED_STUDENT_INFO_H

#include <iostream>
#include <vector>
#include <string>
#include "student_info.h"

class Student_info {
private:
    std::string n;  // public에 name이라는 함수와 이름이 겹쳐서 n으로 설정
    double finalScore;

    std::istream& read_hw(std::istream& in, std::vector<double>& homework);
public:
    Student_info();     // 생성자, 빈 Student_info 객체를 생성
    Student_info(std::istream& in);     // 스트림을 읽어 Student_info 객체 생성

    // name을 n으로 변경
    std::istream& read(std::istream& in);

    std::string name() const;   // 읽기전용, n을 복사한 문자열 반환
    double getFinalScore() const;
};

bool compare(const Student_info& s1, const Student_info& s2);

#endif //ACCELERATED_STUDENT_INFO_H