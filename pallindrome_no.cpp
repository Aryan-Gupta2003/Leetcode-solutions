// Leetcode problem statement link
// https://leetcode.com/problems/palindrome-number/

// Given an integer x, return true if x is a
// palindrome, and false otherwise.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    bool isPalindrome(int x)
    {
        long long n = 0, y = x;
        if (x < 0)
            return false;
        while (x > 0)
        {
            int temp = int(x % 10);
            n = n * 10 + temp;
            x = int(x / 10);
        }
        if (y == n)
        {
            return true;
        }
        else
            return false;
    }
};

// For VSCode
int main()
{
    Solution o1;
    int n = 81518;
    bool result = o1.isPalindrome(n);
    cout << "Number is Palindromic : " << (result == 1 ? "True" : "False") << endl;
    return 0;
}