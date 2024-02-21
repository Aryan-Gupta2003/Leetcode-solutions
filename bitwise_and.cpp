// Leetcode problem statement link
// https://leetcode.com/problems/bitwise-and-of-numbers-range/

// Given two integers left and right that represent the
// range [left, right], return the bitwise AND of all
// numbers in this range, inclusive.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int r = left;
        if (left == right)
            return r;
        for (long long i = left + 1; i <= right; i++)
        {
            r = r & i;
            if (r == 0)
                return r;
        }
        return r;
    }
};

// For VSCode
int main()
{
    Solution o1;
    int left, right;
    cin >> left >> right;
    int result = o1.rangeBitwiseAnd(left, right);
    cout << "Range : [" << left << " , " << right << "]" << endl;
    cout << "Bitwise And Result : " << result << endl;
    return 0;
}