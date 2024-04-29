// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/

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
    int minOperations(vector<int> &nums, int k)
    {
        int ans = 0;
        for (int n : nums)
        {
            ans = ans ^ n;
        }
        int c = 0;
        while (k || ans)
        {
            if ((k % 2) != (ans % 2))
            {
                c++;
            }
            k /= 2;
            ans /= 2;
        }
        return c;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{2, 1, 3, 4};
    int k = 1;
    int result = o1.minOperations(nums, k);
    cout << "Minimum no. of operations to make array XOR equal to K : "
         << result << endl;
    return 0;
}