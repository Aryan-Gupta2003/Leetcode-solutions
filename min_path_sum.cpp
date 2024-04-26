// https://leetcode.com/problems/minimum-falling-path-sum-ii/

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
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), sum = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int j = 0; j < n; j++)
        {
            dp[0][j] = grid[0][j];
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int temp = INT_MAX;
                for (int k = 0; k < n; ++k)
                {
                    if (k != j)
                    {
                        temp = min(temp, grid[i][j] + dp[i - 1][k]);
                    }
                    dp[i][j] = temp;
                }
            }
        }
        for (int j = 0; j < n; ++j)
        {
            sum = min(sum, dp[n - 1][j]);
        }
        return sum;
    }
};

int main()
{
    Solution o1;
    vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int result = o1.minFallingPathSum(grid);
    cout << "Minimum sum of a falling path with non-zero shifts : "
         << result << endl;
    return 0;
}