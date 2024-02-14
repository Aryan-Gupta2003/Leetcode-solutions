#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> p;
        vector<int> n;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
                n.push_back(nums[i]);
            else
                p.push_back(nums[i]);
        }
        vector<int> r;
        for (int i = 0; i < int(nums.size() / 2); i++)
        {
            r.push_back(p[i]);
            r.push_back(n[i]);
        }
        return r;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{2, 3, -1, 4, 10, -3, -7, -9};
    cout << "Array : ";
    for (auto x : nums)
    {
        cout << x << " ";
    }
    vector<int> result = o1.rearrangeArray(nums);
    cout << "\nRearrange elements array : ";
    for (auto y : result)
    {
        cout << y << " ";
    }
    return 0;
}