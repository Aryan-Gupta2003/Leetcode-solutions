// https://leetcode.com/problems/trapping-rain-water/

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
    int trap(vector<int> &height)
    {
        int n = height.size(), water = 0;
        if (n == 0)
            return 0;

        vector<int> left(n);
        vector<int> right(n);

        left[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            left[i] = max(left[i - 1], height[i]);
        }

        right[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = max(right[i + 1], height[i]);
        }

        for (int i = 0; i < n; i++)
        {
            water += min(left[i], right[i]) - height[i];
        }

        return water;
    }
};

int main()
{
    Solution o1;
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int result = o1.trap(height);
    cout << "Trapped Rain Water : " << result << endl;
    return 0;
}