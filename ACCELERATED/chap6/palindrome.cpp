#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::equal;

bool is_palindrome(const string& s)
{
    return equal(s.cbegin(), s.cend(), s.crbegin());
}

int main()
{
    vector<string> words;
    const char *strs[] = {"civic", "korea", "madam", "breeze", "bts"};

    for(int i = 0; i < 5; ++i) {
        words.push_back(string(strs[i]));
    }

    for (vector<string>::const_iterator iter = words.cbegin(); iter != words.cend(); ++iter) {
        cout << *iter << "is palindrome : " << is_palindrome(*iter) << endl;
    }
    return 0;
}