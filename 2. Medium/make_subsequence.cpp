// Leetcode problem statement link
// https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/

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

int main()
{
    Solution o1;
    string s = "coaching", t = "coding";
    int result = o1.appendCharacters(s, t);
    cout << "Minimum no. of characters : " << result << endl;
    return 0;
}