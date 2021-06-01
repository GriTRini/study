#include <string>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::istream;

istream& read_word_count(istream& in, vector<string>& words, vector<int>& counts)
{  
    string word;
        while(in >> word) {

            int i;
            for( i = 0; i < words.size(); ++i) {
                 // 똑같은 글자가 들어오면 탈출
                if(word == words[i]) {      
                break;
                }
            }
        
        
        //vector의 사이즈와 i값이 똑같으면 입력을 더 받는다.
        //그리고  score를 1 증가시킨다.
            if(i == words.size()) {
                words.push_back(word);
                counts.push_back(1);
            } else {
                ++counts[i];
            }

            for (int i = 0; i < words.size(); ++i) {
                cout << words[i] << " : " << counts[i] << endl;
            }
        }
    return in;
}

int main()
{
    vector<string> words;
    vector<int> counts;

    read_word_count(cin, words, counts);

    for (int i = 0; i < words.size(); ++i) {
        cout << words[i] << " : " << counts[i] << endl;
    }
    return 0;
}