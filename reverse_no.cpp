// Leetcode problem statement link
// https://leetcode.com/problems/reverse-integer/

// Given a signed 32-bit integer x, return x with
// its digits reversed. If reversing x causes the
// value to go outside the signed 32-bit integer
// range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to
// store 64-bit integers (signed or unsigned).

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    int reverse(int x)
    {
        long long y = 0, c = 10, i = 1;
        if (x < 0)
        {
            i = -1;
            x = x * i;
        }
        while (x > 0)
        {
            y = y * c + (x % 10);
            if (y > INT_MAX)
                return 0;
            x = int(x / 10);
        }
        return y * i;
    }
};

// For VSCode
int main()
{
    Solution o1;
    int n = -123;
    int result = o1.reverse(n);
    cout << "Number : " << n << endl;
    cout << "Reverse : " << result << endl;
    return 0;
}