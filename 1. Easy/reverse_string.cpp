// Leetcode problem statement link
// https://leetcode.com/problems/reverse-string/

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
    void reverseString(vector<char> &s)
    {
        int n = s.size();
        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
    }
};

void print(vector<char> a)
{
    string sep = "";
    cout << "[";
    for (char x : a)
    {
        cout << sep << "'" << x << "'";
        sep = ", ";
    }
    cout << "]" << endl;
}

int main()
{
    Solution o1;
    vector<char> s{'h', 'e', 'l', 'l', 'o'};
    cout << "String : ";
    print(s);
    o1.reverseString(s);
    cout << "Reverse String : ";
    print(s);
    return 0;
}