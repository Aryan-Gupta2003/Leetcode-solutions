#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        string s = "";

        for (int i = 0; i < number.size(); i++)
        {
            if (number[i] == digit)
            {
                string t = number.substr(0, i) + number.substr(i + 1, number.size());
                s = max(t, s);
            }
        }
        return s;
    }
};

int main()
{
    Solution o1;
    string number = "13125134";
    char digit = '1';
    string result = o1.removeDigit(number, digit);
    cout << "Maximum No after removal of " << digit << " is " << result << endl;
    return 0;
}