// https://leetcode.com/problems/subarrays-with-k-different-integers/

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
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        int temp1 = atmost(nums, k);
        int temp2 = atmost(nums, k - 1);
        return (temp1 - temp2);
    }
    int atmost(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        int left = 0, right = 0, ans = 0;
        while (right < nums.size())
        {
            map[nums[right]]++;
            while (map.size() > k)
            {
                map[nums[left]]--;
                if (map[nums[left]] == 0)
                    map.erase(nums[left]);
                left++;
            }
            ans += right - left + 1;
            right++;
        }
        return ans;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{1, 2, 1, 2, 3};
    int k = 2;
    int result = o1.subarraysWithKDistinct(nums, k);
    cout << "No. of subarrays : " << result << endl;
    return 0;
}