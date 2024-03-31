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
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long a = 0;
        int w = -1, l = -1, r = -1;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (!(minK <= nums[i] && nums[i] <= maxK))
            {
                w = i;
            }

            if (nums[i] == minK)
            {
                l = i;
            }

            if (nums[i] == maxK)
            {
                r = i;
            }

            a += max(0, min(l, r) - w);
        }
        return a;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{1, 3, 5, 2, 7, 5};
    int mink = 1, maxk = 5;
    int result = o1.countSubarrays(nums, mink, maxk);
    cout << "No. of subarrays : " << result << endl;
    return 0;
}