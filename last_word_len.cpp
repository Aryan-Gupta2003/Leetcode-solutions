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
    int lengthOfLastWord(string s)
    {
        int n = s.size(), l = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ' ' && (i != n - 1))
            {
                if (s[i + 1] != ' ')
                {
                    return l;
                }
            }
            if (s[i] != ' ')
                l++;
        }
        return l;
    }
};

int main()
{
    Solution o1;
    string s = "   fly me   to   the moon  ";
    int result = o1.lengthOfLastWord(s);
    cout << "Length of last word : " << result << endl;
    return 0;
}