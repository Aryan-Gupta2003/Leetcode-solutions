// https://leetcode.com/problems/make-the-string-great/

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
    string makeGood(string s)
    {
        int n = s.size();
        if (n == 0 || n == 1)
            return s;
        int i = 0;
        while (i < s.size())
        {
            if (i != s.size() - 1)
            {
                if (((tolower(s[i]) == s[i + 1]) || (toupper(s[i]) == s[i + 1])) && s[i] != s[i + 1])
                {
                    s.erase(i, 2);
                    i = 0;
                    continue;
                }
            }
            i++;
        }
        return s;
    }
};

int main()
{
    Solution o1;
    string s = "leEeetcode";
    string result = o1.makeGood(s);
    cout << "String : " << result << endl;
    return 0;
}