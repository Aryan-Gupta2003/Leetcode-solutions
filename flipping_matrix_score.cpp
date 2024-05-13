// https://leetcode.com/problems/score-after-flipping-matrix/

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
    int matrixScore(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int res = (1 << (m - 1)) * n;
        for (int j = 1; j < m; ++j)
        {
            int val = 1 << (m - 1 - j);
            int set = 0;
            for (int i = 0; i < n; ++i)
            {
                if (grid[i][j] == grid[i][0])
                {
                    set++;
                }
            }
            res += max(set, n - set) * val;
        }
        return res;
    }
};

int main()
{
    Solution o1;
    vector<vector<int>> grid{{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    int result = o1.matrixScore(grid);
    cout << "Score After Flipping Matrix : " << result << endl;
    return 0;
}