// Leetcode problem statement link
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

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
    int numSteps(string s)
    {
        int steps = 0;
        while (s.length() > 1)
        {
            if (s.back() == '0')
            {
                s.pop_back();
            }
            else
            {
                int i = s.length() - 1;
                while (i >= 0 && s[i] == '1')
                {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0)
                {
                    s[i] = '1';
                }
                else
                {
                    s = '1' + s;
                }
            }
            steps++;
        }
        return steps;
    }
};

int main()
{
    Solution o1;
    string s = "1101";
    int result = o1.numSteps(s);
    cout << "Steps Required : " << result << endl;
    return 0;
}