#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        map<int, int> arr;
        for (auto x : nums)
        {
            arr[x]++;
        }
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] >= 2)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{1, 3, 4, 2, 2};
    int result = o1.findDuplicate(nums);
    cout << "Duplicate element : " << result << endl;
    return 0;
}