// https://leetcode.com/problems/number-of-wonderful-substrings/

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
    long long wonderfulSubstrings(string word)
    {
        vector<int> count(1024, 0);
        count[0] = 1;
        long long ans = 0;
        int prefix = 0;
        for (char ch : word)
        {
            int index = ch - 'a';
            prefix ^= 1 << index;
            ans += count[prefix];
            for (int i = 0; i < 10; i++)
            {
                ans += count[prefix ^ (1 << i)];
            }
            count[prefix]++;
        }
        return ans;
    }
};

int main()
{
    Solution o1;
    string word = "aba";
    long long result = o1.wonderfulSubstrings(word);
    cout << "Number of Wonderful Substrings : " << result << endl;
    return 0;
}