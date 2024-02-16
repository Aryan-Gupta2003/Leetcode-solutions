// Leetcode problem statement link
// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/

// Given an array of positive integers nums of length n.
// Return the largest possible perimeter of a polygon
// whose sides can be formed from nums, or -1 if it is
// not possible to create a polygon.

// A polygon is a closed plane figure that has at
// least 3 sides. The longest side of a polygon
// is smaller than the sum of its other sides.

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode
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

// For VSCode
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