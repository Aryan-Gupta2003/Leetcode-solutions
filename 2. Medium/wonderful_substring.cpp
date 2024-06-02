// Leetcode problem statement link
// https://leetcode.com/problems/number-of-wonderful-substrings/

// A wonderful string is a string where at
// most one letter appears an odd number of times.

// For example, "ccjjc" and "abab" are wonderful,
// but "ab" is not. Given a string word that
// consists of the first ten lowercase English
// letters ('a' through 'j'), return the number
// of wonderful non-empty substrings in word.
// If the same substring appears multiple times
// in word, then count each occurrence separately.

// A substring is a contiguous sequence of
// characters in a string.

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
    long long wonderfulSubstrings(string word)
    {
        vector<int> count(1024, 0);
        count[0] = 1;
        long long ans = 0;
        int prefix = 0;
        for (char ch : word)
        {
            int index = ch - 'a';
            prefix ^= 1 << index;
            ans += count[prefix];
            for (int i = 0; i < 10; i++)
            {
                ans += count[prefix ^ (1 << i)];
            }
            count[prefix]++;
        }
        return ans;
    }
};

// For VSCode
int main()
{
    Solution o1;
    string word = "aba";
    long long result = o1.wonderfulSubstrings(word);
    cout << "Number of Wonderful Substrings : " << result << endl;
    return 0;
}