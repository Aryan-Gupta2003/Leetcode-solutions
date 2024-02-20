// Leetcode problem statement link
// https://leetcode.com/problems/zigzag-conversion/

// The string "PAYPALISHIRING" is written in a zigzag
// pattern on a given number of rows like this:

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode
class Solution
{
public:
    string convert(string s, int numRows)
    {
        string p;
        if (numRows == 1)
            return s;
        int n = ((numRows - 1) * 2);
        int j = 0, m = 0;
        while (numRows)
        {
            int w = int(s.size() / 2) + 1;
            int i = j;
            while (w--)
            {
                int k = (i - m), q = (i + n), c = 0;
                if (k > 0 && k < s.size())
                {
                    if (numRows > 1 && m != 0)
                    {
                        p += s[i - m];
                        c = 1;
                    }
                }
                if (i < s.size())
                {
                    p += s[i];
                    c = 1;
                }
                if (c == 0)
                    break;
                i += n;
            }
            numRows--;
            j++;
            m = m + 2;
        }
        return p;
    }
};

// For VSCode
int main()
{
    Solution o1;
    string s = "ABCDE";
    int rows = 2;
    string result = o1.convert(s, rows);
    cout << "String : " << s << endl;
    cout << "After Reading String : " << result << endl;
    return 0;
}