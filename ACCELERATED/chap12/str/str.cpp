//
// Created by user on 2021-06-08.
//
#include <algorithm>
#include <iterator>
#include <cstring>
#include <cctype>
#include "str.h"

using std::strlen;
using std::copy;
using std::back_inserter;
using std::isspace;

std::istream& operator>>(std::istream& in, Str& rhs) {
    rhs.data.clear();

    char c;
    while(in.get(c) && isspace(c))
        ;

    if(in ) {
        do {
            rhs.data.push_back(c);
        } while(in.get(c) && !isspace(c));

        if (in )
            in.unget();
    }

    return in;
}
std::ostream& operator<<(std::ostream& out, const Str& rhs) {
    Vec<char>::size_type i;
    for (i = 0; i != rhs.data.size(); ++i) {
        out << rhs.data[i];
    }

    return out;
}

Str::Str()
        : data() {

}
Str::Str(size_type size, char val)
        : data(size, val) {

}
Str::Str(const char *str)
{
    copy(str, str + strlen(str), back_inserter(this->data));
}
char& Str::operator[](int index) {
    return this->data[index];
}
const char& Str::operator[](int index) const {
    return this->data[index];
}