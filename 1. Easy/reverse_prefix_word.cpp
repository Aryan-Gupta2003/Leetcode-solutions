// Leetcode problem statement link
// https://leetcode.com/problems/reverse-prefix-of-word/

// Given a 0-indexed string word and a character
// ch, reverse the segment of word that starts at
// index 0 and ends at the index of the first
// occurrence of ch (inclusive). If the character
// ch does not exist in word, do nothing.

// For example, if word = "abcdefd" and ch = "d",
// then you should reverse the segment that starts
// at 0 and ends at 3 (inclusive). The resulting
// string will be "dcbaefd".
// Return the resulting string.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    string reversePrefix(string word, char ch)
    {
        string str = "";
        int k = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == ch)
            {
                for (int j = i; j >= 0; j--)
                {
                    str += word[j];
                }
                int p = i;
                while (p >= 0)
                {
                    word[k] = str[k];
                    p--;
                    k++;
                }
                break;
            }
        }
        return word;
    }
};

// For VSCode
int main()
{
    Solution o1;
    string word = "abcdefd";
    char ch = 'd';
    string result = o1.reversePrefix(word, ch);
    cout << "Reverse Prefix of Word : " << result << endl;
    return 0;
}