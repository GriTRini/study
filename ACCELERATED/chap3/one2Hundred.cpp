#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using namespace std;

int main()
{
    // setw는 iomanip에 정의되어 있음
    // setw는 자릿수를 의미한다. 데이터 값은 3자리 이고 setw가 5자리 이면 
    // 앞의 두칸을 공백으로 두고 오른쪽정렬을 시켜서 출력한다.
    for (int i = 1; i <= 100; ++i) {
        cout << setw(3) << i << " : " << setw(5) << i * i << endl;
    }
    return 0;
}