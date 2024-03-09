// Leetcode problem statement link
// https://leetcode.com/problems/count-elements-with-maximum-frequency/

// You are given an array nums
// consisting of positive integers.

// Return the total frequencies of elements
// in nums such that those elements
// all have the maximum frequency.

// The frequency of an element is the
// number of occurrences of that
// element in the array.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        vector<int> arr;
        set<int> a(nums.begin(), nums.end());
        for (auto it : a)
        {
            int c = count(nums.begin(), nums.end(), it);
            arr.push_back(c);
        }
        int max_count = *max_element(arr.begin(), arr.end());
        int c = max_count * count(arr.begin(), arr.end(), max_count);

        return c;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> nums{10, 12, 11, 9, 6, 19, 11};
    int result = o1.maxFrequencyElements(nums);
    cout << "Count Elements With Maximum Frequency : " << result << endl;
    return 0;
}