// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/

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
    long long countSubarrays(vector<int> &nums, int k)
    {
        int m = *max_element(begin(nums), end(nums));
        long long result = 0;

        int l = 0, r = 0, n = nums.size();
        while (r < n)
        {
            k -= (nums[r++] == m);
            while (k == 0)
            {
                k += (nums[l++] == m);
            }
            result += l;
        }
        return result;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{1, 3, 2, 3, 3};
    int k = 2;
    long long result = o1.countSubarrays(nums, k);
    cout << "No. of subarrays : " << result << endl;

    return 0;
}