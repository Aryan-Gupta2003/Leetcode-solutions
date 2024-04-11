// https://leetcode.com/problems/remove-k-digits/

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
    string removeKdigits(string num, int k)
    {
        if (num.size() == k)
            return "0";

        string result;
        for (char &digit : num)
        {
            while (k > 0 && !result.empty() && digit < result.back())
            {
                result.pop_back();
                k--;
            }
            result.push_back(digit);
        }

        while (k > 0)
        {
            result.pop_back();
            k--;
        }

        int i = 0;
        while (i < result.size() && result[i] == '0')
        {
            i++;
        }
        result.erase(0, i);

        if (result.empty())
            return "0";

        return result;
    }
};

int main()
{
    Solution o1;
    string num = "1234567890";
    int k = 9;
    string result = o1.removeKdigits(num, k);
    cout << "String after k digit removal : " << result << endl;
    return 0;
}