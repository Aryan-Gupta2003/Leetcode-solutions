#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    Solution o1;
    vector<string> words{"how", "who", "wow", "what"};
    string result = o1.firstPalindrome(words);
    cout << "First Pallindromic string : " << result;
    return 0;
}