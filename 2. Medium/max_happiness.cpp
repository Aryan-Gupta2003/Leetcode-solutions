// Leetcode problem statement link
// https://leetcode.com/problems/maximize-happiness-of-selected-children/

// You are given an array happiness of length n,
// and a positive integer k.

// There are n children standing in a queue, where
// the ith child has happiness value happiness[i].
// You want to select k children from these n children
// in k turns.

// In each turn, when you select a child, the happiness
// value of all the children that have not been selected
// till now decreases by 1. Note that the happiness value
// cannot become negative and gets decremented only if it
// is positive.

// Return the maximum sum of the happiness values of the
// selected children you can achieve by selecting k children.

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

// For VSCode
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