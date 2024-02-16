// Leetcode problem statement link
// https://leetcode.com/problems/longest-substring-without-repeating-characters/

// Given a string s, find the length of the longest
// substring without repeating characters.

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string r = "";
        int m = 0, l = 0, i = 0, j = 0;
        while (i < s.length())
        {
            if (r.find(s[i]) == string::npos)
            {
                r += s[i];
                l++;
            }
            else
            {
                if (m < l)
                {
                    m = l;
                }
                l = 0;
                r = "";
                i = j;
                j++;
            }
            i++;
        }
        m = (m < l) ? l : m;
        return m;
    }
};

// For VSCode
int main()
{
    Solution o1;
    string words = "abcdabced";
    int result = o1.lengthOfLongestSubstring(words);
    cout << "String : " << words << endl;
    cout << "Length of longest substring without repeating characters : "
         << result << endl;
    return 0;
}