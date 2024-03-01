#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int l = s.size();
        int c = count(s.begin(), s.end(), '1');
        string r;
        if (c == 1 && c < l)
        {
            r = string((l - 1), '0') + '1';
            return r;
        }
        else if (c == l)
        {
            r = string(c, '1');
            return r;
        }
        else
        {
            r = string((c - 1), '1') + string((l - c), '0') + '1';
            return r;
        }
    }
};

int main()
{
    Solution o1;
    string s = "001001101";
    string result = o1.maximumOddBinaryNumber(s);
    cout << "Maximum Odd Binary No. : " << result << endl;
    return 0;
}