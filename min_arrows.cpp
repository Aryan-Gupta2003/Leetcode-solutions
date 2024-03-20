#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int a = 1;
        int prev = points[0][1];

        for (int i = 1; i < points.size(); i++)
        {
            if (points[i][0] > prev)
            {
                a++;
                prev = points[i][1];
            }
        }

        return a;
    }
};

int main()
{
    Solution o1;
    vector<vector<int>> arr{{10, 16}, {2, 8}, {1, 6}, {7, 2}};
    int result = o1.findMinArrowShots(arr);
    cout << "Minimum Number of Arrows to Burst Balloons : " << result << endl;

    return 0;
}