// Leetcode problem statement link
// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/

// You are given an array nums of non-negative
// integers. nums is considered special if there
// exists a number x such that there are exactly x
// numbers in nums that are greater than or equal to x.

// Notice that x does not have to be an element in nums.

// Return x if the array is special, otherwise,
// return -1. It can be proven that if nums is
// special, the value for x is unique.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int specialArray(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, c = 0, s = n;
        sort(nums.begin(), nums.end(), greater<int>());
        while (i != n)
        {
            if (s <= nums[i])
            {
                c++;
                i++;
                continue;
            }
            else
            {
                if (c == s)
                    return c;
                s--;
                i = 0;
                c = 0;
            }
        }
        if (c == s)
            return c;
        return -1;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> nums{0, 4, 3, 0, 4};
    int result = o1.specialArray(nums);
    cout << "Value of x : " << result << endl;
    return 0;
}