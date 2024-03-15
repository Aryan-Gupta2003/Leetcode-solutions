#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> pre(n, 1);
        vector<int> suffix(n, 1);

        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        vector<int> ans(n);
        for (int i = 0; i < n; ++i)
        {
            ans[i] = pre[i] * suffix[i];
        }

        return ans;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{1, 2, 3, 4};
    vector<int> result = o1.productExceptSelf(nums);
    cout << "Product Array : ";
    for (auto x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}