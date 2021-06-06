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
    for (int i = 1; i <= 1000; ++i) {
        cout << setw(4) << i << " : " << setw(7) << i * i << endl;
    }
    return 0;
}