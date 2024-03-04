#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    Solution o1;
    vector<vector<int>> grid{{7, 2, 9}, {1, 5, 0}, {2, 6, 6}};
    int k = 20;
    int result = o1.countSubmatrices(grid, k);
    cout << "Maximum Count : " << result << endl;
    return 0;
}