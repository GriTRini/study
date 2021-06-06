#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "please enter your name : ";
    string name;    // name을 string으로 선언
    cin >> name;    // name에 cin으로 입력

    const string greeting = "hello, " + name;   // greeting에 name을 넣음 const로 바꾸지 않음

    const int pad = 1;  //pad를 1로 선언
    //const int rows = 2 * pad + 3;
    const string::size_type rows = 2 * pad + 3; // 행 제작
    const string::size_type cols = greeting.size() + 2 * pad + 2;   // 열 제작

    cout << endl;
    for (int r = 0; r != rows; ++r) {   // r이 rows의 크기가 되기 전까지 1씩 증가함
        string::size_type c = 0;    // c는 string의 size_type이다.

        while (c != cols) {     // c가 cols와 같지 않으면 실행, 같으면 종료
            // 문장 출력
            if (r == pad + 1 && c == pad + 1) {   
                cout << greeting;   // 문장 출력
                c += greeting.size();   // c는 열이므로 글자가 출력된 이후에 문자의 크기만큼 증가함
            }else {
                // 테두리 or 빈칸 출력
                if (r == 0 || r == rows - 1 || c == 0 || c == cols -1) 
                    cout << '*';
                else {
                    cout << ' ';
                    }
                ++c;
                
            }
        }
        cout << endl;
    }
    return 0;

}