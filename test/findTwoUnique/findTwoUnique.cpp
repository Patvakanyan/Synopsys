
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 2, 1, 4, 5, 5};

    int xorResult = 0;

    for (int num : arr)
        xorResult ^= num;

    vector<int> first;
    vector<int> second;

    int bit = 1;

    while ((xorResult & bit) == 0)
        bit <<= 1;

    for (int num : arr)
    {
        if (num & bit)
            first.push_back(num);
        else
            second.push_back(num);
    }

    int unique1 = 0;
    int unique2 = 0;

    for (int num : first)
        unique1 ^= num;

    for (int num : second)
        unique2 ^= num;

    cout << unique1 << " " << unique2 << endl;

    return 0;
}

