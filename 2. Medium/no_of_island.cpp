// Leetcode problem statement link
// https://leetcode.com/problems/number-of-islands/

// Given an m x n 2D binary grid grid which
// represents a map of '1's (land) and '0's
// (water), return the number of islands.

// An island is surrounded by water and is
// formed by connecting adjacent lands
// horizontally or vertically. You may
// assume all four edges of the grid are
// all surrounded by water.

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
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
        {
            return;
        }

        grid[i][j] = '0';
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }

        int numIslands = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    numIslands++;
                    dfs(grid, i, j);
                }
            }
        }
        return numIslands;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<vector<char>> grid{{'1', '1', '1', '1', '0'},
                              {'1', '1', '0', '1', '0'},
                              {'1', '1', '0', '0', '0'},
                              {'0', '0', '0', '0', '0'}};
    int result = o1.numIslands(grid);
    cout << "No. of Islands : " << result << endl;
    return 0;
}