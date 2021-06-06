#ifndef ACCELERATED_SPLIT_H
#define ACCELERATED_SPLIT_H
#include <string>
#include <algorithm>

using namespace std;

bool not_space(char c);
bool space(char c);

template <typename Out>
void split(const string& s, Out os) {
    string::const_iterator  iter = s.begin();
    while (iter != s.end()) {
        iter = find_if(iter, s.end(), not_space);
        string::const_iterator iter2 = find_if(iter, s.end(), space);

        if (iter != iter2)
            *os++ = string(iter, iter2);

        iter = iter2;
    }
}

#endif