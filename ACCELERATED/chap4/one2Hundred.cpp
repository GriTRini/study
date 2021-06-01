#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using std::sort;
using std::vector;
using std::domain_error;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::setprecision;
using std::cerr;
using std::max;
using std::setw;

int main()
{
    for (int i = 1; i <= 100; ++i) {
        cout << setw(3) << i << " : " << setw(5) << i * i << endl;
    }
    return 0;
}