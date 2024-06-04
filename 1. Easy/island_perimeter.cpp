// Leetcode problem statement link
// https://leetcode.com/problems/island-perimeter/

// You are given row x col grid representing
// a map where grid[i][j] = 1 represents land
// and grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/
// vertically (not diagonally). The grid
// is completely surrounded by water, and
// there is exactly one island (i.e., one
// or more connected land cells).

// The island doesn't have "lakes", meaning
// the water inside isn't connected to the
// water around the island. One cell is a
// square with side length 1. The grid is
// rectangular, width and height don't exceed
// 100. Determine the perimeter of the island.

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
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int p = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid[r][c] == 1)
                {
                    p += 4;
                    if (r > 0 && grid[r - 1][c] == 1)
                    {
                        p -= 2;
                    }
                    if (c > 0 && grid[r][c - 1] == 1)
                    {
                        p -= 2;
                    }
                }
            }
        }
        return p;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<vector<int>> grid{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    int result = o1.islandPerimeter(grid);
    cout << "Island Perimeter : " << result << endl;
    return 0;
}