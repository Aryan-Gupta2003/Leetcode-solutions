// Leetcode problem statement link
// https://leetcode.com/problems/two-sum/

// Given an array of integers nums and an integer
// target, return indices of the two numbers such
// that they add up to target

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            vector<int>::iterator it;
            it = find(nums.begin(), nums.end(), (target - nums[i]));
            int j = int(it - nums.begin());
            if (it != nums.end() && i != j)
            {
                return {i, j};
            }
        }
        return {};
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> nums{2, 3, 4, 10};
    int target = 6;
    vector<int> result = o1.twoSum(nums, target);
    cout << "Indeces are : ";
    for (auto x : result)
    {
        cout << x << " ";
    }
    return 0;
}