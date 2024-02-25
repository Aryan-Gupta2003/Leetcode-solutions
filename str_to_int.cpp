#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 1, a = int('0'), x, y, z;
        long long b = 0;
        for (x = 0; x < s.size(); x++)
        {
            if (isdigit(s[x]))
                break;
            else if (int(s[x]) != int(' '))
            {
                if (int(s[x]) == int('-'))
                {
                    i = -1;
                    x++;
                    break;
                }
                else if (int(s[x]) == int('+'))
                {
                    i = 1;
                    x++;
                    break;
                }
                else if (int(s[x]) != a)
                {
                    break;
                }
            }
        }
        for (y = x; y < s.size(); y++)
        {
            if (!isdigit(s[y]))
                return 0;
            else if (int(s[y]) != a)
                break;
        }
        for (z = y; z < s.size(); z++)
        {
            if (!isdigit(s[z]))
                break;
            b = b * 10 + (int(s[z]) - a);
            if (b - 1 > INT_MAX)
            {
                b = INT_MAX;
                b++;
                break;
            }
        }

        b = b * i;

        if (b > INT_MAX)
        {
            b = INT_MAX;
        }

        return b;
    }
};

int main()
{
    Solution o1;
    string s = "  +134";
    int result = o1.myAtoi(s);
    cout << "Integer : " << result << endl;
    return 0;
}