// https://leetcode.com/problems/valid-parenthesis-string/

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
    bool checkValidString(string s)
    {
        int l = 0, r = 0;
        for (char x : s)
        {
            if (x == '(')
            {
                l++;
                r++;
            }
            else if (x == ')')
            {
                l--;
                r--;
            }
            else
            {
                l--;
                r++;
            }
            if (r < 0)
                return false;
            if (l < 0)
                l = 0;
        }
        return l == 0;
    }
};

int main()
{
    Solution o1;
    string s = "(*))";
    bool result = o1.checkValidString(s);
    cout << "Valid Parenthesis String : " << (result == 1 ? "True" : "False") << endl;
    return 0;
}