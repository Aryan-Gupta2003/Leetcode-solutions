// Leetcode problem statement link
// https://leetcode.com/problems/rearrange-array-elements-by-sign/

// Given a 0-indexed integer array nums of even length
// consisting of an equal number of positive and negative integers.

// Rearrange the elements of nums such that the
// modified array follows the given conditions:

// 1. Every consecutive pair of integers have opposite signs.
// 2. For all integers with the same sign, the order in which
//    they were present in nums is preserved.
// 3. The rearranged array begins with a positive integer.

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> p;
        vector<int> n;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                n.push_back(nums[i]);
            else
                p.push_back(nums[i]);
        }
        vector<int> r;
        for (int i = 0; i < int(nums.size() / 2); i++)
        {
            r.push_back(p[i]);
            r.push_back(n[i]);
        }
        return r;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> nums{2, 3, -1, 4, 10, -3, -7, -9};
    cout << "Array : ";
    for (auto x : nums)
    {
        cout << x << " ";
    }
    vector<int> result = o1.rearrangeArray(nums);
    cout << "\nRearrange elements array : ";
    for (auto y : result)
    {
        cout << y << " ";
    }
    return 0;
}