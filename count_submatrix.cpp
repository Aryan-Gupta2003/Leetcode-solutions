// Leetcode problem statement link
// https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/

// You are given a 0-indexed integer matrix
// grid and an integer k.

// Return the number of submatrices that
// contain the top-left element of the grid,
// and have a sum less than or equal to k.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (i >= 1)
                    grid[i][j] += grid[i - 1][j];
                if (j >= 1)
                    grid[i][j] += grid[i][j - 1];
                if (i >= 1 && j >= 1)
                    grid[i][j] -= grid[i - 1][j - 1];
                if (grid[i][j] <= k)
                    count++;
            }
        }
        return count;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<vector<int>> grid{{7, 2, 9}, {1, 5, 0}, {2, 6, 6}};
    int k = 20;
    int result = o1.countSubmatrices(grid, k);
    cout << "Maximum Count : " << result << endl;
    return 0;
}