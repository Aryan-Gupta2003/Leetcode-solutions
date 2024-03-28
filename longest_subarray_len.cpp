// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // To reduce time complexity
    // In VSCode we can use it
    // in main function also
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        map<int, int> m;
        int n = nums.size();
        int l = 0, r = 0, c{};
        while (r < n)
        {
            int i = nums[r++];
            m[i]++;
            while (l < r && m[i] > k)
            {
                m[nums[l++]]--;
            }
            c = max(c, r - l);
        }
        return c;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{1, 2, 3, 1, 2, 3, 1, 2};
    int k = 2;
    int result = o1.maxSubarrayLength(nums, k);
    cout << "Longest subarray length : " << result << endl;

    return 0;
}