// Leetcode problem statement link
// https://leetcode.com/problems/largest-local-values-in-a-matrix/

// You are given an n x n integer matrix grid.

// Generate an integer matrix maxLocal of size
// (n - 2) x (n - 2) such that:

// maxLocal[i][j] is equal to the largest value
// of the 3 x 3 matrix in grid centered around
// row i + 1 and column j + 1.
// In other words, we want to find the largest
// value in every contiguous 3 x 3 matrix in grid.

// Return the generated matrix.

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
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2));
        for (int i = 1; i < n - 1; ++i)
        {
            for (int j = 1; j < n - 1; ++j)
            {
                int temp = 0;

                for (int k = i - 1; k <= i + 1; ++k)
                {
                    for (int l = j - 1; l <= j + 1; ++l)
                    {
                        temp = max(temp, grid[k][l]);
                    }
                }
                res[i - 1][j - 1] = temp;
            }
        }
        return res;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<vector<int>> grid{{9, 9, 8, 1}, {5, 6, 2, 6}, {8, 2, 6, 4}, {6, 2, 2, 2}};
    vector<vector<int>> res = o1.largestLocal(grid);
    string sep = "", sep2 = "";
    cout << "Largest Local Values in a Matrix : [";
    for (auto x : res)
    {
        cout << sep2 << "[";
        sep2 = ", ";
        for (auto y : x)
        {
            cout << sep << y;
            sep = ", ";
        }
        cout << "]";
        sep = "";
    }
    cout << "]" << endl;
    return 0;
}