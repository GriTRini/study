//
// Created by user on 2021-06-09.
//

#include <iostream>

using namespace  std;

int main()
{
    int x = 5;

    // p는 x를 가리킴.
    int *p = &x;
    cout << "x = " << x << endl;

    // p를 이용해 x 값을 변경
    *p = 6;
    cout << "x = " << x << endl;

    return 0;
}