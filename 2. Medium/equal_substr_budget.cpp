// Leetcode problem statement link
// https://leetcode.com/problems/get-equal-substrings-within-budget/

// You are given two strings s and t of
// the same length and an integer maxCost.

// You want to change s to t. Changing
// the ith character of s to ith character
// of t costs |s[i] - t[i]| (i.e., the
// absolute difference between the ASCII
// values of the characters).

// Return the maximum length of a substring
// of s that can be changed to be the same
// as the corresponding substring of t with
// a cost less than or equal to maxCost. If
// there is no substring from s that can be
// changed to its corresponding substring
// from t, return 0.

#include <bits/stdc++.h>
using namespace std;

// Sol FOr Leetcode
class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int equalSubstring(string s, string t, int maxCost)
    {
        int n = s.length(), maxLen = 0;
        int cost = 0, start = 0;

        for (int i = 0; i < n; i++)
        {
            cost += abs(s[i] - t[i]);

            while (cost > maxCost)
            {
                cost -= abs(s[start] - t[start]);
                start++;
            }
            maxLen = max(maxLen, i - start + 1);
        }
        return maxLen;
    }
};

// For VSCode
int main()
{
    Solution o1;
    string s = "krpgjbjjznpzdfy", t = "nxargkbydxmsgby";
    int m = 14;
    int result = o1.equalSubstring(s, t, m);
    cout << "Maximum Substring : " << result << endl;
    return 0;
}