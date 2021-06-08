#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 회문 확인하기
bool is_palindrome(const string& s)
{
    // rebegin은 컨테이너의 마지막 요소에서 시작하여 컨테이너를 거꾸로 통과합니다.
    // equal은 순서가 반대인 두 문자열이 같은 값인지 판별하려고 두 순차열을 비교한다.
    // equal(begin~end, 두번째 순차열의 시작지점)
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