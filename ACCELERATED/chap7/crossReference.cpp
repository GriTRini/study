#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;;

bool is_not_space(char c)
{
    return !isspace(c);
}

bool is_space(char c)
{
    return isspace(c);
}

vector<string> split(const string& s)
{
    vector<string> words;


    for (string::const_iterator it = s.cbegin(); it != s.cend() ; )
    {
        // 선행 공백을 무시
        // find_if(처음배열, 끝배열, 조건)
        it = find_if(it, s.cend(), is_not_space);

        // 다음 단어의 끝을 찾음
        string::const_iterator it2 = find_if(it, s.cend(), is_space);

        // it, it2 범위의 문자를 복사
        // it과 it2는 인덱스가 아니라 반복자 이다.
        if (it != it2) {
            words.push_back(string(it, it2));
        }

        it = it2;
    }
    return words;
}

// 입력에서 각 단어가 등장한 모든 행을 찾음
map<string, vector<int> > xref(istream& in, vector<string> (*find_words)(const string&) = split)
{
    // >>에 공백이 없으면 기호 2개가 아닌 >> 연산자로 인식해서 공백이 필요함
    map<string, vector<int> > ret;
    int lineNumber = 0;
    string line;

    // 다음 행을 읽음
    while (getline(in, line)) {
        ++lineNumber;

        // 지역 변수 words를 선언하고 find_words 함수로 초기화
        // find_words 함수는 행을 각 단어로 나누는 split 함수 거나 문자열 인수를 절달받아 그 결과로 vector<string>을 반환
        vector<string> words = find_words(line);

        // 현재 행에 등장한 모든 단어를 저장
        typedef vector<string>::const_iterator vec_citer;
        // for문으로 words 벡ㅌ의 각요소를 탐색하면서 ret의 내용을 갱신한다.
        for (vec_citer iter = words.cbegin(); iter != words.cend(); ++iter) {
            ret[*iter].push_back(lineNumber);
        }
    }

    return ret;
}

int main()
{
    // ret을 선언해준후에 xref 함수에 cin으로 받은 값을 치환
    map<string, vector<int> > ret;
    ret = xref(cin);

    typedef map<string, vector<int> >::const_iterator map_citer;
    // map_citer에 ret 처음부터 마지막까지 반복하면서 결과출력
    for (map_citer iter = ret.cbegin(); iter != ret.cend(); ++iter) {
        // 첫번째 행 출력
        cout << iter->first << " : ";

        typedef vector<int>::const_iterator vec_citer;
        for (vec_citer iter2 = iter->second.cbegin(); iter2 != iter->second.cend(); ++iter2) {
            // 두번째 행 출력
            cout << *iter2 << " ";
        }
        cout << endl;
    }

    return 0;
}