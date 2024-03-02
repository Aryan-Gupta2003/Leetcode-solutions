// Leetcode problem statement link
// https://leetcode.com/problems/majority-element/

// Given an array nums of size n, return
// the majority element.

// The majority element is the element that appears
// more than ⌊n / 2⌋ times. You may assume that
// the majority element always exists in the array.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int c = 0, n = nums.size(), a = nums[0];
        for (int i = 0; i < n; i++)
        {
            if (a != nums[i])
            {
                if (c > int(n / 2))
                {
                    break;
                }
                c = 1;
                a = nums[i];
            }
            else
                c += 1;
        }
        return a;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> n{2, 1, 1, 0, 1, 3, 1};

    cout << "Square Sorted Array : ";
    int result = o1.majorityElement(n);
    cout << "Maximum element: " << result << endl;
    return 0;
}