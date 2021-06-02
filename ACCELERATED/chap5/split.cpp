#include <iostream>
#include <list>
#include <algorithm>
#include <stdexcept>
#include <ios>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::sort;
using std::max;
using std::list;
using std::string;
using std::istream;
using std::domain_error;
using std::streamsize;
using std::cerr;
using std::vector;

vector<string> split(const string& s)
{
    vector<string> words;

    for (string::size_type i = 0; i != s.size(); ) {
        while ( i != s.size() && isspace(s[i]))
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