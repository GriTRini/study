#include <iostream>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<string> split(const string& s)
{
    vector<string> words;
    // 문장의 공백을 찾아서 단어로 나눔

    for (string::size_type i = 0; i != s.size(); ) {
        while ( i != s.size() && isspace(s[i]))     // <cctype>, isspace는 해당 객체가 공백인지 나타내는 값을 반환하는 함수
            ++i;
        string::size_type j = i;
        while (j != s.size() && !isspace(s[j]))      
           ++j;

        if (i != j) {
            words.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return words;
}

string::size_type width(const vector<string>& words)
{   
    string::size_type max = 0;

    typedef vector<string>::const_iterator vec_citer;
    for (vec_citer iter = words.begin(); iter != words.end(); ++iter) {
        max = ::max(max, iter->size());
    }
    return max;
}

vector<string> frame(const vector<string>& words)
{
    vector<string> result;
    const string::size_type maxLen = width(words);

    string border(width(words) + 4, '*');

    result.push_back(border);
    for (vector<string>::const_iterator iter = words.begin(); iter != words.end(); ++ iter) {
        result.push_back("* " + *iter + string(maxLen - iter->size(), ' ') + " *");
    }
    result.push_back(border);

    return result;
}
int main() 
{
    //const string s = "knocking on the heaven's door";
    string s;
    while (getline(cin, s)) {
        const vector<string> words = split(s);
    

        typedef vector<string>::const_iterator vec_citer;
        for (vec_citer iter = words.begin(); iter != words.end(); ++iter) {
            cout << *iter << endl;
        }

        const vector<string> frameWords = frame(words);
        typedef vector<string>::const_iterator vec_citer;
        for (vec_citer iter = frameWords.begin(); iter != frameWords.end(); ++iter) {
            cout << *iter << endl;
        }
    }
    return 0;
}