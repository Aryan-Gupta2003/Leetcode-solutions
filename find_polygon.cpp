#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        vector<int> side;
        side = nums;
        sort(side.begin(), side.end());

        int c = side.size();
        long long p = 0;
        for (int x : side)
            p += x;
        for (int i = c - 1; i >= 0; i--)
        {
            if ((p - side[i]) <= side[i])
            {
                p -= side[i];
                c -= 1;
            }

            else
                break;
        }
        p = (c >= 3) ? p : -1;
        return p;
    }
};

int main()
{
    Solution o1;
    vector<int> nums{2, 3, 1, 4, 50, 3, 7, 9};
    cout << "Array : ";
    for (auto x : nums)
    {
        cout << x << " ";
    }
    cout << endl;
    int result = o1.largestPerimeter(nums);
    cout << "Largest Perimeter : " << result << endl;
    return 0;
}