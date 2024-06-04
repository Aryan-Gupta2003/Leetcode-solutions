// Leetcode problem statement link
// https://leetcode.com/problems/longest-palindrome/

#include <bits/stdc++.h>
#include <unordered_set>
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
    int longestPalindrome(string s)
    {
        unordered_set<char> alpha;
        int length = 0;
        for (char c : s)
        {
            if (alpha.find(c) != alpha.end())
            {
                alpha.erase(c);
                length += 2;
            }
            else
            {
                alpha.insert(c);
            }
        }
        if (!alpha.empty())
        {
            length += 1;
        }
        return length;
    }
};

int main()
{
    Solution o1;
    string s = "abccccdd";
    int result = o1.longestPalindrome(s);
    cout << "Longest Palindrome : " << result << endl;
    return 0;
}