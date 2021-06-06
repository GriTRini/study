#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

template<typename T>

T median(vector<T>& vec)
{
    typedef typename vector<T>::size_type vec_sz;
    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("median of an empty vector");
    }
    sort(vec.begin(), vec.end());
    
    const int mid = vec.size() / 2;
    return (vec.size() % 2 == 1) ? vec[mid] : (vec[mid] + vec[mid -1]) / 2;
}

int main()
{
    int arr[] = {10, 30, 20, 40, 100, 80, 50, 60, 70, 90};
    vector<int> nums(arr, arr + 10);

    cout << "median : " << median(nums) << endl;
    return 0;
}