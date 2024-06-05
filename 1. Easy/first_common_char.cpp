// Leetcode problem statement link
// https://leetcode.com/problems/find-common-characters/

// Given a string array words, return an array
// of all characters that show up in all strings
// within the words (including duplicates). You
// may return the answer in any order.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
private:
    vector<int> count(const string &str)
    {
        vector<int> freq(26, 0);
        for (char c : str)
        {
            freq[c - 'a']++;
        }
        return freq;
    }

    vector<int> intersection(const vector<int> &a, const vector<int> &b)
    {
        vector<int> t(26, 0);
        for (int i = 0; i < 26; i++)
        {
            t[i] = min(a[i], b[i]);
        }
        return t;
    }

public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<string> commonChars(vector<string> &words)
    {
        vector<int> last = count(words[0]);
        for (int i = 1; i < words.size(); i++)
        {
            last = intersection(last, count(words[i]));
        }
        vector<string> s;
        for (int i = 0; i < 26; i++)
        {
            while (last[i] > 0)
            {
                s.push_back(string(1, 'a' + i));
                last[i]--;
            }
        }
        return s;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<string> words{"bella", "label", "roller"};
    string sep = "";
    vector<string> result = o1.commonChars(words);
    cout << "Common characters : [";
    for (string x : result)
    {
        cout << sep << "'" << x << "'";
        sep = ", ";
    }
    cout << "]" << endl;
    return 0;
}