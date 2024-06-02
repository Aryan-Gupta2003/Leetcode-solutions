// Leetcode problem statement link
// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

// Given an integer array nums that does not
// contain any zeros, find the largest positive
// integer k such that -k also exists in the array.

// Return the positive integer k. If there is no
// such integer, return -1.

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
    int findMaxK(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > 0 && std::binary_search(nums.begin(), nums.end(), -nums[i]))
            {
                return nums[i];
            }
        }
        return -1;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> nums{-1, 2, -3, 3};
    int result = o1.findMaxK(nums);
    cout << "Largest Positive Integer That Exists With Its Negative : "
         << result << endl;
    return 0;
}