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
using std::streamsize;
using std::cerr;
using std::max;
using std::setw;

int main ()
{
    std::streamsize prec = cout.precision();
    cout << std::setprecision(2);
    
    for (double x = 1; x <= 100; x += 1.0) {
        cout << setw(6) << std::fixed << x << " : " << setw(11) << std::fixed << x * x << endl;
    }

    cout << std::setprecision(prec);
    return 0;
}