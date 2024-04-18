// https://leetcode.com/problems/island-perimeter/

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

int main()
{
    Solution o1;
    vector<vector<int>> grid{{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
    int result = o1.islandPerimeter(grid);
    cout << "Island Perimeter : " << result << endl;
    return 0;
}