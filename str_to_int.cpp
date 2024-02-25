// Leetcode problem statement link
// https://leetcode.com/problems/string-to-integer-atoi/

// Implement the function, which converts a
// string to a 32-bit signed integer.

// The algorithm for myAtoi(string s) is as follows:

// 1. Read in and ignore any leading whitespace.
// 2. Check if the next character (if not already at the end of
//    the string) is '-' or '+'. Read this character in if it is
//    either. This determines if the final result is negative or
//    positive respectively. Assume the result is positive if
//    neither is present.
// 3. Read in next the characters until the next non-digit
//    character or the end of the input is reached. The
//    rest of the string is ignored.
// 4. Convert these digits into an integer (i.e. "123" -> 123,
//    "0032" -> 32). If no digits were read, then the integer is 0.
//    Change the sign as necessary (from step 2).
// 5. If the integer is out of the 32-bit signed integer range
//    [-231, 231 - 1], then clamp the integer so that it remains in the
//    range. Specifically, integers less than -231 should be clamped to
//    -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
// 6. Return the integer as the final result.

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode
class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 1, a = int('0'), x, y, z;
        long long b = 0;
        for (x = 0; x < s.size(); x++)
        {
            if (isdigit(s[x]))
                break;
            else if (int(s[x]) != int(' '))
            {
                if (int(s[x]) == int('-'))
                {
                    i = -1;
                    x++;
                    break;
                }
                else if (int(s[x]) == int('+'))
                {
                    i = 1;
                    x++;
                    break;
                }
                else if (int(s[x]) != a)
                {
                    break;
                }
            }
        }
        for (y = x; y < s.size(); y++)
        {
            if (!isdigit(s[y]))
                return 0;
            else if (int(s[y]) != a)
                break;
        }
        for (z = y; z < s.size(); z++)
        {
            if (!isdigit(s[z]))
                break;
            b = b * 10 + (int(s[z]) - a);
            if (b - 1 > INT_MAX)
            {
                b = INT_MAX;
                b++;
                break;
            }
        }

        b = b * i;

        if (b > INT_MAX)
        {
            b = INT_MAX;
        }

        return b;
    }
};

// For VSCode
int main()
{
    Solution o1;
    string s = "  +134";
    int result = o1.myAtoi(s);
    cout << "Integer : " << result << endl;
    return 0;
}