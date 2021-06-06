#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using namespace std;

int main ()
{
    streamsize prec = cout.precision();     
    cout << setprecision(2);        // 소수점 2번째 자리 까지 출력
    
    for (double x = 1; x <= 100; x += 1.0) {
        cout << setw(6) <<  fixed << x << " : " << setw(11) <<  fixed << x * x << endl;
    }

    cout <<  setprecision(prec);
    return 0;
}