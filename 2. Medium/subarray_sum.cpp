// Leetcode problem statement link
// https://leetcode.com/problems/continuous-subarray-sum/

// Given an integer array nums and an integer k,
// return true if nums has a good subarray or false otherwise.

// A good subarray is a subarray where:

// its length is at least two, and the sum of the
// elements of the subarray is a multiple of k.
// Note that:
// A subarray is a contiguous part of the array.
// An integer x is a multiple of k if there exists an
// int n such that x = n * k. 0 is always a multiple of k.

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
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int sum = nums[0];
        int len = nums.size();
        int index, tempSum;
        for (int i = 1; i < len; i++)
        {
            if (nums[i] == nums[i - 1] && nums[i] == 0)
                return true;

            sum += nums[i];
            if (sum % k == 0)
                return true;

            index = 0;
            tempSum = sum;
            while ((i - index) > 1 && tempSum >= k)
            {
                tempSum -= nums[index++];
                if (tempSum % k == 0)
                    return true;
            }
        }
        return false;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> nums{23, 2, 4, 6, 7};
    int k = 6;
    bool result = o1.checkSubarraySum(nums, k);
    cout << "Continuous Subarray Sum : " << (result == 1 ? "True" : "False") << endl;
    return 0;
}