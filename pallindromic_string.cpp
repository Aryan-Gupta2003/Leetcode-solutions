// Leetcode problem statement link
// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/

// Given an array of strings words, return the first
// palindromic string in the array. If there is no
// such string, return an empty string ""

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode
class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            string str = words[i];
            reverse(str.begin(), str.end());
            if (words[i] == str)
                return words[i];
        }
        return "";
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<string> words{"how", "who", "wow", "what"};
    string result = o1.firstPalindrome(words);
    cout << "First Pallindromic string : " << result;
    return 0;
}