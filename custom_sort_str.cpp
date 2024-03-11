// Leetcode problem statement link
// https://leetcode.com/problems/custom-sort-string/

// You are given two strings order and s. All the
// characters of order are unique and were sorted
// in some custom order previously.

// Permute the characters of s so that they match the
// order that order was sorted. More specifically, if
// a character x occurs before a character y in order,
// then x should occur before y in the permuted string.

// Return any permutation of s that satisfies this property.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
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

// For VSCode
int main()
{
    Solution o1;
    string order = "bcafw";
    string s = "kabcjgdwya";
    string result = o1.customSortString(order, s);
    cout << "Custom Sort String : " << result << endl;
    return 0;
}