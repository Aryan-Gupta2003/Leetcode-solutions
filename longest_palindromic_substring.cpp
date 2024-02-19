// Leetcode problem statement link
// https://leetcode.com/problems/longest-palindromic-substring/

// Given a string s, return the longest palindromic substring in s.

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode

class Solution
{
public:
    string longestPalindrome(string str)
    {
        int n = str.length();
        bool t[n][n];

        memset(t, 0, sizeof(t));
        int maxL = 1, s = 0;

        for (int i = 0; i < n; i++)
            t[i][i] = true;

        for (int i = 0; i < n - 1; i++)
        {
            if (str[i] == str[i + 1])
            {
                t[i][i + 1] = true;
                s = i;
                maxL = 2;
            }
        }

        for (int k = 3; k <= n; k++)
        {
            for (int i = 0; i < n - k + 1; i++)
            {
                int j = i + k - 1;
                if (t[i + 1][j - 1] && str[i] == str[j])
                {
                    t[i][j] = true;

                    if (maxL < k)
                    {
                        s = i;
                        maxL = k;
                    }
                }
            }
        }
        string r = "";
        for (int i = s; i <= (s + maxL - 1); i++)
            r += str[i];
        return r;
    }
};

// For VSCode
int main()
{
    Solution o1;
    string str = "hellolled";
    string result = o1.longestPalindrome(str);
    cout << "String : " << str << endl;
    cout << "Longest Pallindromic Substring : " << result << endl;
    return 0;
}