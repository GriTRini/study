#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "please enter your name : ";
    string name;
    cin >> name;

    const string greeting = "hello, " + name;

    const int pad = 2;
    //const int rows = 2 * pad + 3;
    const string::size_type rows = 2 * pad + 3;
    const string::size_type cols = greeting.size() + 2 * pad + 2;
    cout << endl;
    for (int r = 0; r != rows; ++r) {
        if (r == rows/2 ) {
            cout << '*' << string(pad, ' ') << greeting << string(pad, ' ') << "*";
        } else if (r == 0 || r == rows - 1  ) {
            cout << string(cols, '*');
        } else {
            cout << '*' << string(cols - 2, ' ')  << "*";
        }
    

        
        cout << endl;
    }
    return 0;

}