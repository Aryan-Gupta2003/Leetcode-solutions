// Leetcode problem statement link
// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

// You are given two strings s and t consisting
// of only lowercase English letters.

// Return the minimum number of characters that
// need to be appended to the end of s so that
// t becomes a subsequence of s.

// A subsequence is a string that can be derived
// from another string by deleting some or no
// characters without changing the order of the
// remaining characters.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int appendCharacters(string s, string t)
    {
        int n = s.size(), m = t.size();
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            if (s[i] == t[j])
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        return (m - j);
    }
};

// For VSCode
int main()
{
    Solution o1;
    string s = "coaching", t = "coding";
    int result = o1.appendCharacters(s, t);
    cout << "Minimum no. of characters : " << result << endl;
    return 0;
}