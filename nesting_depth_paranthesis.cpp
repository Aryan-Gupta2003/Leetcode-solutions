// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

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
    int maxDepth(string s)
    {
        int n = s.size();
        if (n == 0 || (n == 1 && (s[0] != '(' && s[0] != ')')))
            return 0;
        int c = 0, m = 0;
        for (char x : s)
        {
            if (x == '(')
            {
                c++;
                if (m < c)
                {
                    m = c;
                }
            }
            else if (x == ')')
            {
                c--;
            }
        }
        return m;
    }
};

int main()
{
    Solution o1;
    string s = "(1)+((2))+(((3)))";
    int result = o1.maxDepth(s);
    cout << "Nesting Depth : " << result << endl;
    return 0;
}