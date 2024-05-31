// Leetcode problem statement link
// https://leetcode.com/problems/single-number-iii/description/

// Given an integer array nums, in which
// exactly two elements appear only once
// and all the other elements appear
// exactly twice. Find the two elements
// that appear only once. You can return
// the answer in any order.

// You must write an algorithm that runs
// in linear runtime complexity and uses
// only constant extra space.

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
    vector<int> singleNumber(vector<int> &nums)
    {
        int XOR = accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
        int i = 0, a = 0, b = 0;
        while (((XOR >> i) & 1) == 0)
            i++;

        for (int x : nums)
        {
            if (((x >> i) & 1) == 0)
                a ^= x;
            else
                b ^= x;
        }
        return {a, b};
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> nums{1, 2, 1, 3, 2, 5};
    vector<int> result = o1.singleNumber(nums);
    cout << "Numbers : [" << result[0] << ", "
         << result[1] << "]" << endl;
    return 0;
}