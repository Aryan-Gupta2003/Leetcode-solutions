// Leetcode problem statement link
// https://leetcode.com/problems/power-of-two/

// Given an integer n, return true if it is a
// power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2^x.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
        {
            return false;
        }
        while (n != 1)
        {
            if (n % 2 != 0)
                return false;
            else
                n = n / 2;
        }
        return true;
    }
};

// For VSCode
int main()
{
    Solution o1;
    int n = 64;
    cout << "Number : " << n << endl;
    bool result = o1.isPowerOfTwo(n);
    cout << "No. is in power of 2 : " << (result == 1 ? "True" : "False") << endl;
    return 0;
}