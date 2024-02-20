// Leetcode problem statement link
// https://leetcode.com/problems/missing-number/

// Given an array nums containing n distinct numbers
// in the range [0, n], return the only number in
// the range that is missing from the array.

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        vector<int> n;
        n = nums;
        sort(n.begin(), n.end());
        int i;
        for (i = 0; i < n.size(); i++)
        {
            if (i != n[i])
                return i;
        }
        return i;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> nums{2, 3, 1, 4, 0, 6, 7, 8};
    cout << "Array : ";
    for (auto x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
    int result = o1.missingNumber(nums);
    cout << "Missing No. : " << result << endl;
    return 0;
}