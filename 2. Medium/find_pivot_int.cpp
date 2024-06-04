// Leetcode problem statement link
// https://leetcode.com/problems/find-the-pivot-integer/

// Given a positive integer n, find the pivot
// integer x such that:

// The sum of all elements between 1 and x
// inclusively equals the sum of all elements
// between x and n inclusively.
// Return the pivot integer x. If no such
// integer exists, return -1. It is guaranteed
// that there will be at most one pivot index
// for the given input.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    int pivotInteger(int n)
    {
        int i = 1, j = n;
        int prefix = i, suffix = j;
        while (i <= j)
        {
            if ((i == j) && (prefix == suffix))
                return i;
            if (prefix <= suffix)
            {
                i++;
                prefix += i;
            }
            else
            {
                j--;
                suffix += j;
            }
        }
        return -1;
    }
};

// For VSCode
int main()
{
    Solution o1;
    int n = 8;
    int result = o1.pivotInteger(n);
    cout << "Pivot Integer : " << result << endl;
    return 0;
}