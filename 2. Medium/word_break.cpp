// Leetcode problem statement link
// https://leetcode.com/problems/word-break/

// Given a string s and a dictionary of strings
// wordDict, return true if s can be segmented
// into a space-separated sequence of one or more dictionary words.

#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

// Sol for Leetcode
class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    int getMaxLength(const vector<string> &wordDict)
    {
        return max_element(begin(wordDict), end(wordDict), [](const auto &a, const auto &b)
                           { return a.length() < b.length(); })
            ->length();
    }

    bool wordBreak(string s, vector<string> &wordDict)
    {
        const int n = s.length();
        const int maxLength = getMaxLength(wordDict);
        const unordered_set<string> wordSet{begin(wordDict), end(wordDict)};
        vector<int> dp(n + 1);
        dp[0] = true;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                if (i - j > maxLength)
                    break;
                if (dp[j] && wordSet.count(s.substr(j, i - j)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

// For VSCode
int main()
{
    Solution o1;
    string s = "catsanddog", sep = "";
    vector<string> wordDict{"cat", "cats", "and", "sand", "dog"};
    bool result = o1.wordBreak(s, wordDict);
    cout << "Valid Sentence(s) : " << (result == 1 ? "True" : "False");
    return 0;
}