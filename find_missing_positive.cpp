#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; ++i)
        {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
            {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{1, 2, 0};
    int result = o1.firstMissingPositive(nums);
    cout << result << endl;
    return 0;
}