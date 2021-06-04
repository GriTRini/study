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

    for (string::const_iterator it = s.cbegin(); it != s.cend();) {
        it = find_if (it, s.cend(), is_not_space);

        string::const_iterator it2 = find_if(it, s.cend(), is_space);
        if (it != it2) {
            words.push_back(string(it, it2));
        }

        it = it2;
    }

    return words;
}

map<string, vector<int> > xref(istream& in, 
                            vector<string> (*find_words)(const string&) = split) 
{
    map<string, vector<int> > ret;

    int lineNumber = 0;
    string line;
    while (getline(in, line)) {
        ++lineNumber;

        vector<string> words = find_words(line);

        typedef vector<string>::const_iterator vec_citer;
        for (vec_citer iter = words.cbegin(); iter != words.cend(); ++iter) {
            ret[*iter].push_back(lineNumber);
        }
    }

    return ret;
}

int main()
{   
    map<string, vector<int> > ret;
    ret = xref(cin);

    typedef map<string, vector<int> >::const_iterator map_citer;

    for (map_citer iter = ret.cbegin(); iter != ret.cend(); ++iter) {
        cout << iter->first << " : ";
    
 
        typedef vector<int>::const_iterator vec_citer;
        for (vec_citer iter2 = iter->second.cbegin(); iter2 != iter->second.cend(); ++iter2) {
            cout << *iter2 << " ";
        }
        cout << endl;
    }

    return 0;
}