// Leetcode problem statement link
// https://leetcode.com/problems/distribute-elements-into-two-arrays-i/

// You are given a 1-indexed array of distinct
// integers nums of length n.

// You need to distribute all the elements of
// nums between two arrays arr1 and arr2 using
// n operations. In the first operation, append
// nums[1] to arr1. In the second operation,
// append nums[2] to arr2. Afterwards,
// in the ith operation:

// If the last element of arr1 is greater than
// the last element of arr2, append nums[i] to
// arr1. Otherwise, append nums[i] to arr2.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        vector<int> arr1;
        vector<int> arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int n1 = 0, n2 = 0;
        for (int i = 2; i < nums.size(); i++)
        {
            if (arr1[n1] > arr2[n2])
            {
                arr1.push_back(nums[i]);
                n1 += 1;
            }
            else
            {
                arr2.push_back(nums[i]);
                n2 += 1;
            }
        }
        for (int i = 0; i < arr2.size(); i++)
        {
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> nums{5, 4, 3, 8, 7, 1, 2, 6, 9};
    vector<int> result = o1.resultArray(nums);
    cout << "Merged array : ";
    for (auto x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}