// Leetcode problem statement link
// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/

// Given a string s consisting only of characters
// 'a', 'b', and 'c'. You are asked to apply the
// following algorithm on the string any number of times:

// 1. Pick a non-empty prefix from the string s
//    where all the characters in the prefix are equal.
// 2. Pick a non-empty suffix from the string s
//    where all the characters in this suffix are equal.
// 3. The prefix and the suffix should not
//    intersect at any index.
// 4. The characters from the prefix and
//    suffix must be the same.
// 5. Delete both the prefix and the suffix.

// Return the minimum length of s after performing
// the above operation any number of times (possibly zero times).

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution1
{
public:
    int minimumLength(string s)
    {
        int n = s.size(), l, r;
        for (l = 0, r = n - 1; l < r && s[l] == s[r]; l++, r--)
        {
            while (s[l] == s[l + 1] && (l + 1) < r)
                l++;
            while (s[r] == s[r - 1] && l < (r - 1))
                r--;
        }
        return r - l + 1;
    }
};

class Solution2
{
public:
    string c_prefix(string &a)
    {
        string b = "";
        b += a[0];
        for (int i = 1; i < a.size(); i++)
        {
            if (b[0] == a[i])
            {
                b += a[i];
            }
            else
            {
                break;
            }
        }
        return b;
    }
    string c_suffix(string &a, int l)
    {
        string b = "";
        int n = a.size() - 1;
        b += a[n];
        for (int i = n - 1; i > l; i--)
        {
            if (b[0] == a[i])
            {
                b += a[i];
            }
            else
            {
                break;
            }
        }
        return b;
    }
    int minimumLength(string s)
    {
        while (s.size() > 0)
        {
            string prefix = c_prefix(s);
            string suffix = c_suffix(s, prefix.size());
            if (suffix[0] == prefix[0] && s.size() != 1)
            {
                s = s.substr(prefix.size(), s.size() - (suffix.size() + prefix.size()));
            }
            else
            {
                return s.size();
            }
        }
        return 0;
    }
};

// For VSCode
int main()
{
    Solution1 o1;
    string s = "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb";
    int result = o1.minimumLength(s);
    cout << "String : " << s << endl;
    cout << "Minimum Length of String After Deleting Similar Ends : "
         << result << endl;
    return 0;
}