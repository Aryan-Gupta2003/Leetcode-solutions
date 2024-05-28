// Leetcode problem statement link
// https://leetcode.com/problems/get-equal-substrings-within-budget/

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

int main()
{
    Solution o1;
    string s = "krpgjbjjznpzdfy", t = "nxargkbydxmsgby";
    int m = 14;
    int result = o1.equalSubstring(s, t, m);
    cout << "Maximum Substring : " << result << endl;
    return 0;
}