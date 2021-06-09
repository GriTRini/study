//
// Created by user on 2021-06-08.
//

#ifndef ACCELERATED_STR_H
#define ACCELERATED_STR_H

#include <algorithm>
#include <iterator>
#include "vec.h"



class Str {
    friend std::istream& operator>>(std::istream& in, Str& rhs);
    friend std::ostream& operator<<(std::ostream& out, const Str& rhs);

public:
    typedef size_t size_type;

    Str();
    Str(size_type size, char val);
    Str(const char *str);       //explict Str s1 = "hello"; 가 가능할 수 있으니까 안쓴다.
//    Str(const char *b, const char *e);
//    Str(Vec<char>::const_iterator b, Vec<char>::const_iterator e);
    template <typename In>
    Str(In b, In e);

    char& operator[](int index);
    const char& operator[](int index) const;
private:
    Vec<char> data;
};

template <typename In>
Str::Str(In b, In e) {
    std::copy(b, e, std::back_inserter(this->data));
}

#endif //ACCELERATED_STR_H