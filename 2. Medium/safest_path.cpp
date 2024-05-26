// Leetcode problem statement link
// https://leetcode.com/problems/find-the-safest-path-in-a-grid/

// You are given a 0-indexed 2D matrix grid
// of size n x n, where (r, c) represents:
// A cell containing a thief if grid[r][c] = 1
// An empty cell if grid[r][c] = 0
// You are initially positioned at cell (0, 0).
// In one move, you can move to any adjacent cell
// in the grid, including cells containing thieves.

// The safeness factor of a path on the grid is
// defined as the minimum manhattan distance from
// any cell in the path to any thief in the grid.
// Return the maximum safeness factor of all paths
// leading to cell (n - 1, n - 1).

// An adjacent cell of cell (r, c), is one of the
// cells (r, c + 1), (r, c - 1), (r + 1, c) and
// (r - 1, c) if it exists.
// The Manhattan distance between two cells (a, b)
// and (x, y) is equal to |a - x| + |b - y|, where
// |val| denotes the absolute value of val.

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
    vector<int> roww = {0, 0, -1, 1};
    vector<int> coll = {-1, 1, 0, 0};

    void bfs(vector<vector<int>> &grid, vector<vector<int>> &score, int n)
    {
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    score[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            int s = score[x][y];
            for (int i = 0; i < 4; i++)
            {
                int newX = x + roww[i];
                int newY = y + coll[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n && score[newX][newY] > 1 + s)
                {
                    score[newX][newY] = 1 + s;
                    q.push({newX, newY});
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1])
            return 0;

        vector<vector<int>> score(n, vector<int>(n, INT_MAX));
        bfs(grid, score, n);
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({score[0][0], {0, 0}});

        while (!pq.empty())
        {
            auto temp = pq.top().second;
            auto safe = pq.top().first;
            pq.pop();

            if (temp.first == n - 1 && temp.second == n - 1)
                return safe;
            vis[temp.first][temp.second] = true;

            for (int i = 0; i < 4; i++)
            {
                int newX = temp.first + roww[i];
                int newY = temp.second + coll[i];
                if (newX >= 0 && newX < n && newY >= 0 && newY < n && !vis[newX][newY])
                {
                    int s = min(safe, score[newX][newY]);
                    pq.push({s, {newX, newY}});
                    vis[newX][newY] = true;
                }
            }
        }
        return -1;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<vector<int>> grid{{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    int result = o1.maximumSafenessFactor(grid);
    cout << "Maximum safeness factor : " << result << endl;
    return 0;
}