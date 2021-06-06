#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace  std;

int main()
{
    vector<string> words;   // vector<인자> 이름
    cout << "plese enter your words : ";
    string word;  // word를 string으로 선언
    // string으로 선언한 word에 cin으로 넣으면서 vector로 선언한 words에 push_back하여 넣는다.
    // 한칸씩 vector에 넣는 다는 의미임
    while (cin >> word) {   
        words.push_back(word);
    }

    // vector의 words의 size만큼 진행시키면서 words를 출력
    for (int i = 0; i < words.size(); ++i) {
        cout << words[i] <<endl;
    }

    //words의 첫번째 문자열의 크기를 각각 Max와 Min으로 설정
    string Maxstring = words[0];
    string Minstring = words[0];

    // 첫번째 문자열의 크기로 설정한 후에 i를 증가시키면서 다음 오는 문자열의 크기가 Max보다 크면
    // 해당 문자열을 Max로 설정하고 Min 보다 작으면 Min으로 설정한다.
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