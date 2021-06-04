#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    map<string, int> counters;

    string s;
    while (cin >> s) {
        ++counters[s];
    }

    for (map<string, int>::const_iterator iter = counters.cbegin(); iter != counters.cend(); ++iter) {
        cout << iter->first << " : " << iter->second << endl;
    }

    return 0;
}