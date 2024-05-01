// https://leetcode.com/problems/reverse-prefix-of-word/

#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    Solution o1;
    string word = "abcdefd";
    char ch = 'd';
    string result = o1.reversePrefix(word, ch);
    cout << "Reverse Prefix of Word : " << result << endl;
    return 0;
}