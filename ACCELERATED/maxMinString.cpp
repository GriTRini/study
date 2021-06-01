#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> words;
    cout << "plese enter your words : ";
    string word;
    while (cin >> word) {
        words.push_back(word);
    }

    for (int i = 0; i < words.size(); ++i) {
        cout << words[i] <<endl;
    }

    string Maxstring = words[0];
    string Minstring = words[0];

    for (int i = 1; i < words.size(); ++i) {
        if(Maxstring.size() < words[i].size()) {
            Maxstring = words[i];
        }
        if(Minstring.size() > words[i].size()) {
            Minstring = words[i];
        }
    }

    cout << "Max length string : " << Maxstring << endl;
    cout << "Min length string : " << Minstring << endl;
      


    return 0;
}