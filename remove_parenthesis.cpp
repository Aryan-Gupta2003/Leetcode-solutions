// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

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
    string minRemoveToMakeValid(string s)
    {
        stack<int> stack;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                stack.push(i);
            }
            else if (s[i] == ')')
            {
                if (!stack.empty())
                {
                    stack.pop();
                }
                else
                {
                    s[i] = '*';
                }
            }
        }

        while (!stack.empty())
        {
            s[stack.top()] = '*';
            stack.pop();
        }

        string a;
        for (char x : s)
        {
            if (x != '*')
            {
                a += x;
            }
        }

        return a;
    }
};

int main()
{
    Solution o1;
    string s = "lee(t(c)o)de)";
    string result = o1.minRemoveToMakeValid(s);
    cout << "String : " << result << endl;
    return 0;
}