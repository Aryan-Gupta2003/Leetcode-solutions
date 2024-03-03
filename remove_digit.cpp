// Leetcode problem statement link
// https://leetcode.com/problems/remove-digit-from-number-to-maximize-result/

// Given a string number representing a positive
// integer and a character digit.

// Return the resulting string after removing exactly
// one occurrence of digit from number such that the
// value of the resulting string in decimal form is
// maximized. The test cases are generated such that
// digit occurs at least once in number.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
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

// For VSCode
int main()
{
    Solution o1;
    string number = "13125134";
    char digit = '1';
    string result = o1.removeDigit(number, digit);
    cout << "Maximum No after removal of " << digit << " is " << result << endl;
    return 0;
}