#include <string>
#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> words;
    vector<int> score;

    cout << "input student score" << endl;

    string word;
    while(cin >> word) {

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
            score.push_back(1);
        } else {
            ++score[i];
        }

        for (int i = 0; i < words.size(); ++i) {
            cout << words[i] << " : " << score[i] << endl;
        }
    }
    return 0;
}