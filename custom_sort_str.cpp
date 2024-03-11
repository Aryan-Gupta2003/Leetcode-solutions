// Leetcode problem statement link
// https://leetcode.com/problems/apple-redistribution-into-boxes/

// You are given an array apple of size n and an
// array capacity of size m.

// There are n packs where the ith pack contains
// apple[i] apples. There are m boxes as well, and
// the ith box has a capacity of capacity[i] apples.

// Return the minimum number of boxes you need to
// select to redistribute these n packs of apples
// into boxes.

// Note that, apples from the same pack can be
// distributed into different boxes.

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