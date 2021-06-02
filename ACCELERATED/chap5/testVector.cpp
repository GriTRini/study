#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> nums;
    vector<int> nums2(10, 0);
    vector<int> nums3(nums2.begin(), nums2.end());
    vector<int> nums4 = nums3;

    int arr[] = {1, 2, 3, 4, 5};
    vector<int> nums5(arr, arr + 5);

    cout << "size : " << nums.size() << endl;
    cout << "capacity : " << nums.capacity() << endl;
    cout << "max_size : " << nums.max_size() << endl;
    
    nums.reserve(5);//capacity를 미리 할당 해놓음으로써 push_back을 할때마다 늘어나는 것을 막음으로써 오버헤드를 줄일수 있다
    for (int i = 1; i <= 10; ++i) {
        cout << "push_back :" << i << endl;
        nums.push_back(i);
        cout << "size : " << nums.size() << endl;
        cout << "capacity : " << nums.capacity() << endl;
        cout << "max_size : " << nums.max_size() << endl;
    }

    for (int i  = 0; i < nums5.size(); ++i) {
        cout << nums5[i] << " ";
    }
    cout << endl;

    for (vector<int>::size_type i = 0; i != nums5.size(); ++i)
        cout << nums5[i] << " ";
    cout << endl;

    for (vector<int>::const_iterator iter = nums5.begin(); iter != nums5.end(); ++iter)
        cout << *iter << " ";
    cout << endl;

    // for (vector<int>::const_iterator iter = nums5.cbegin(); iter != nums5.cend(); ++iter)
    //     cout << *iter << " ";
    // cout << endl;

    for (vector<int>::const_reverse_iterator iter = nums5.rbegin(); iter != nums5.rend(); ++iter)
        cout << *iter << " ";
    cout << endl;

    // for (vector<int>::const_reverse_iterator iter = nums5.crbegin(); iter != nums5.crend(); ++iter)
    //     cout << *iter << " ";
    // cout << endl;

    return 0;
}