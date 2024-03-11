#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string customSortString(string order, string s)
    {
        string a;
        for (auto x : order)
        {
            int c = count(s.begin(), s.end(), x);
            if (c > 0)
            {
                a += string(c, x);
                s.erase(remove(s.begin(), s.end(), x), s.end());
                if (s.size() == 0)
                {
                    return a;
                }
            }
        }
        a += s;
        return a;
    }
};

int main()
{
    Solution o1;
    string order = "bcafw";
    string s = "kabcjgdwya";
    string result = o1.customSortString(order, s);
    cout << "Custom Sort String : " << result << endl;
    return 0;
}