#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> arr;
        for (int x : nums)
        {
            int i = abs(x) - 1;
            if (nums[i] < 0)
            {
                arr.push_back(i + 1);
            }
            else
            {
                nums[i] = -nums[i];
            }
        }
        return arr;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};
    string sep = "";
    vector<int> result = o1.findDuplicates(nums);
    cout << "Duplicate elements : [";
    for (int x : result)
    {
        cout << sep << x;
        sep = ", ";
    }
    cout << "]" << endl;

    return 0;
}