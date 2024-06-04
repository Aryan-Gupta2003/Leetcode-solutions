// Leetcode problem statement link
// https://leetcode.com/problems/cherry-pickup-ii/

// You are given a rows x cols matrix grid representing a
// field of cherries where grid[i][j] represents the no.
// of cherries that you can collect from the (i, j) cell.

// You have two robots that can collect
// cherries for you:
// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using
// both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1),
// (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all
// cherries, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return dfs(grid, n, m, 0, 0, m - 1, dp);
    }

    int dfs(vector<vector<int>> &grid, int n, int m, int r, int col1, int col2, vector<vector<vector<int>>> &dp)
    {
        if (r < 0 || r >= n || col1 < 0 || col1 >= m || col2 < 0 || col2 >= m)
        {
            return 0;
        }
        if (dp[r][col1][col2] != -1)
        {
            return dp[r][col1][col2];
        }
        int maxCherries = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int newCol1 = col1 + i;
                int newCol2 = col2 + j;
                maxCherries = max(maxCherries, dfs(grid, n, m, r + 1, newCol1, newCol2, dp));
            }
        }
        int currCherry = (col1 == col2) ? grid[r][col1] : grid[r][col1] + grid[r][col2];
        dp[r][col1][col2] = currCherry + maxCherries;
        return dp[r][col1][col2];
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<vector<int>> grid{{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    int result = o1.cherryPickup(grid);
    cout << "Maximum no. of cherries : " << result << endl;
    return 0;
}