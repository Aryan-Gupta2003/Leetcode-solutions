// Leetcode problem statement link
// https://leetcode.com/problems/longest-ideal-subsequence/

// You are given a string s consisting of lowercase
// letters and an integer k. We call a string t ideal
// if the following conditions are satisfied:
// t is a subsequence of the string s.
// The absolute difference in the alphabet order of every
// two adjacent letters in t is less than or equal to k.
// Return the length of the longest ideal string.

// A subsequence is a string that can be derived from another
// string by deleting some or no characters without changing
// the order of the remaining characters.

// Note that the alphabet order is not cyclic.
// For example,the absolute difference in the
// alphabet order of 'a' and 'z' is 25, not 1.

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
    int longestIdealString(string s, int k)
    {
        int dp[150] = {}, c = 0;
        for (auto &i : s)
        {
            for (int j = i - k; j <= i + k; ++j)
                dp[i] = max(dp[i], dp[j]);
            c = max(c, ++dp[i]);
        }
        return c;
    }
};

// For VSCode
int main()
{
    Solution o1;
    string s = "acfgbd";
    int k = 2;
    int result = o1.longestIdealString(s, k);
    cout << "Longest Ideal Subsequence : " << result << endl;
    return 0;
}