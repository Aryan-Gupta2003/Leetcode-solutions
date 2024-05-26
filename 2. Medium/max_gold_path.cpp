// https://leetcode.com/problems/path-with-maximum-gold/

// In a gold mine grid of size m x n,
// each cell in this mine has an integer
// representing the amount of gold in
// that cell, 0 if it is empty.

// Return the maximum amount of gold
// you can collect under the conditions:

// Every time you are located in a cell
// you will collect all the gold in that cell.
// From your position, you can walk one step
// to the left, right, up, or down. You
// can't visit the same cell more than once.
// Never visit a cell with 0 gold. You
// can start and stop collecting gold from
// any position in the grid that has some gold.

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
    vector<int> roww = {1, -1, 0, 0};
    vector<int> coll = {0, 0, -1, 1};
    int maxGold = 0;

    int dfs(vector<vector<int>> &grid, int x, int y, int n, int m)
    {
        if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0)
            return 0;
        int curr = grid[x][y];
        grid[x][y] = 0;
        int localMaxGold = curr;
        for (int i = 0; i < 4; i++)
        {
            int newX = x + roww[i];
            int newY = y + coll[i];
            localMaxGold = max(localMaxGold, curr + dfs(grid, newX, newY, n, m));
        }
        grid[x][y] = curr;
        return localMaxGold;
    }

    int getMaximumGold(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)
                {
                    maxGold = max(maxGold, dfs(grid, i, j, n, m));
                }
            }
        }
        return maxGold;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<vector<int>> grid{{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    int result = o1.getMaximumGold(grid);
    cout << "Maximum amount of gold : " << result << endl;
    return 0;
}