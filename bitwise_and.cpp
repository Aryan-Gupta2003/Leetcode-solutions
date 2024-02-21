// Leetcode problem statement link
// https://leetcode.com/problems/bitwise-and-of-numbers-range/

// Given two integers left and right that represent the
// range [left, right], return the bitwise AND of all
// numbers in this range, inclusive.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution1
{
public:
    int rangeBitwiseAnd1(int left, int right)
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

class Solution2
{
public:
    int rangeBitwiseAnd2(int left, int right)
    {
        int s = 0;

        // Find the common high-order bits of left and right
        while (left < right)
        {
            left >>= 1;
            right >>= 1;
            s++;
        }

        // Shift back the common high-order bits to their original position
        return left << s;
    }
};

class Solution3
{
public:
    int rangeBitwiseAnd3(int left, int right)
    {
        while (right > left)
        {
            right = (right & (right - 1));
        }
        return right;
    }
};

// For VSCode
int main()
{
    Solution1 o1;
    Solution2 o2;
    Solution3 o3;
    int left, right;
    cin >> left >> right;
    int result1 = o1.rangeBitwiseAnd1(left, right);
    int result2 = o2.rangeBitwiseAnd2(left, right);
    int result3 = o3.rangeBitwiseAnd3(left, right);
    cout << "Range : [" << left << " , " << right << "]" << endl;
    cout << "Bitwise And Result with class 1 : " << result1 << endl;
    cout << "Bitwise And Result with class 2 : " << result2 << endl;
    cout << "Bitwise And Result with class 3 : " << result3 << endl;
    return 0;
}