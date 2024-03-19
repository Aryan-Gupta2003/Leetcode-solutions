#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        int sum = 0;
        int length = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i] == 0 ? -1 : 1;
            if (sum == 0)
            {
                length = i + 1;
            }
            else if (mp.find(sum) != mp.end())
            {
                length = max(length, i - mp[sum]);
            }
            else
            {
                mp[sum] = i;
            }
        }
        return length;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1};
    int result = o1.findMaxLength(nums);
    cout << "Maximum length of a contiguous subarray : " << result << endl;
    return 0;
}