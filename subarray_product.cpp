#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;

        int c = 0, p = 1;
        int left = 0;

        for (int right = 0; right < nums.size(); right++)
        {
            p *= nums[right];
            while (p >= k)
            {
                p /= nums[left++];
            }
            c += (right - left + 1);
        }

        return c;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{10, 5, 2, 6};
    int k = 100;
    int result = o1.numSubarrayProductLessThanK(nums, k);
    cout << "No. of contiguous subarrays : " << result << endl;

    return 0;
}