// https://leetcode.com/problems/maximize-happiness-of-selected-children/

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
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        sort(begin(happiness), end(happiness), greater<int>());
        int i = 0;
        long long ans = 0;

        while (k--)
        {
            happiness[i] = max(happiness[i] - i, 0);
            ans += happiness[i++];
        }
        return ans;
    }
};

int main()
{
    Solution o1;
    vector<int> happiness{1, 2, 3};
    int k = 2;
    long long result = o1.maximumHappinessSum(happiness, k);
    cout << "Maximize Happiness of Selected Children : "
         << result << endl;
    return 0;
}