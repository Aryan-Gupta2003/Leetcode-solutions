#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int l = nums.size();
        for (int i = 0; i < l; i++)
        {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

int main()
{
    Solution o1;
    vector<int> n{-4, -2, -1, 0, 1, 3, 5};

    cout << "Square Sorted Array : ";
    vector<int> result = o1.sortedSquares(n);
    for (auto x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}