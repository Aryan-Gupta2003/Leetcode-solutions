// Leetcode problem statement link
// https://leetcode.com/problems/maximum-odd-binary-number/

// You are given a binary string s that contains
// at least one '1'.

// You have to rearrange the bits in such a way that
// the resulting binary number is the maximum odd
// binary number that can be created from this combination.

// Return a string representing the maximum odd binary
// number that can be created from the given combination.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int l = s.size();
        int c = count(s.begin(), s.end(), '1');
        string r;
        if (c == 1 && c < l)
        {
            r = string((l - 1), '0') + '1';
            return r;
        }
        else if (c == l)
        {
            r = string(c, '1');
            return r;
        }
        else
        {
            r = string((c - 1), '1') + string((l - c), '0') + '1';
            return r;
        }
    }
};

// For VSCode
int main()
{
    Solution o1;
    string s = "001001101";
    string result = o1.maximumOddBinaryNumber(s);
    cout << "Maximum Odd Binary No. : " << result << endl;
    return 0;
}