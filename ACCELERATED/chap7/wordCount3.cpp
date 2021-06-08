#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // 각 단어와 빈도를 저장하는 맵
    // 입력을 읽으면서 각 단어와 빈도를 저장
    // 키 타입인 string과 값 타입인 int 의 값이 있는 맵인 counters를 정의
    map<string, int> counters;

    string s;
    // 한번에 한단어찍 s로 읽어 들인다
    while (cin >> s) {
        // s에 저장한 문자열과 연관된 정수값
        // 아직 존재하지 않는 키로맵에 접근할 때 맵은 해당 단어를 키로 갖느 새로운 요소를 자동으로 만듦 (값초기화)

        ++counters[s];
    }

    for (map<string, int>::const_iterator iter = counters.cbegin(); iter != counters.cend(); ++iter) {
        cout << iter->first << " : " << iter->second << endl;
    }

    return 0;
}