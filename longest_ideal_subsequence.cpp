// https://leetcode.com/problems/longest-ideal-subsequence/

#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    Solution o1;
    string s = "acfgbd";
    int k = 2;
    int result = o1.longestIdealString(s, k);
    cout << "Longest Ideal Subsequence : " << result << endl;
    return 0;
}