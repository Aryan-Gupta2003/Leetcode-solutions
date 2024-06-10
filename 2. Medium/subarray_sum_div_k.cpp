// Leetcode problem statement link
// https://leetcode.com/problems/subarray-sums-divisible-by-k/

// Given an integer array nums and an integer k, return
// the number of non-empty subarrays that have a sum divisible by k.

// A subarray is a contiguous part of an array.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int count = 0;
        int prefixSum = 0;
        std::unordered_map<int, int> prefixMap;
        prefixMap[0] = 1;
        for (int num : nums)
        {
            prefixSum += num;
            int mod = prefixSum % k;
            if (mod < 0)
            {
                mod += k;
            }
            if (prefixMap.find(mod) != prefixMap.end())
            {
                count += prefixMap[mod];
                prefixMap[mod] += 1;
            }
            else
            {
                prefixMap[mod] = 1;
            }
        }
        return count;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> nums{4, 5, 0, -2, -3, 1};
    int k = 5;
    int result = o1.subarraysDivByK(nums, k);
    cout << "No. of non-empty subarrays : " << result << endl;
    return 0;
}