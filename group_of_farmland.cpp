// Leetcode problem statement link
// https://leetcode.com/problems/find-all-groups-of-farmland/

// You are given a 0-indexed m x n binary matrix
// land where a 0 represents a hectare of forested
// land and a 1 represents a hectare of farmland.

// To keep the land organized, there are designated
// rectangular areas of hectares that consist entirely
// of farmland. These rectangular areas are called
// groups. No two groups are adjacent, meaning farmland
// in one group is not four-directionally adjacent to
// another farmland in a different group.

// land can be represented by a coordinate system where
// the top left corner of land is (0, 0) and the bottom
// right corner of land is (m-1, n-1). Find the coordinates
// of the top left and bottom right corner of each group
// of farmland. A group of farmland with a top left corne
// at (r1, c1) and a bottom right corner at (r2, c2) is
// represented by the 4-length array [r1, c1, r2, c2].

// Return a 2D array containing the 4-length arrays
// described above for each group of farmland in land.
// If there are no groups of farmland, return an empty
// array. You may return the answer in any order.

#include <bits/stdc++.h>
#include <unordered_set>
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
    vector<vector<int>> findFarmland(vector<vector<int>> &land)
    {
        int rows = land.size();
        int cols = land[0].size();
        unordered_set<string> visited;
        vector<vector<int>> result;

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (land[i][j] == 1 && visited.find(to_string(i) + "," + to_string(j)) == visited.end())
                {
                    vector<int> bounds = dfs(land, visited, i, j);
                    result.push_back(bounds);
                }
            }
        }
        return result;
    }

    vector<int> dfs(vector<vector<int>> &land, unordered_set<string> &visited, int x, int y)
    {
        stack<pair<int, int>> stack;
        stack.push({x, y});
        visited.insert(to_string(x) + "," + to_string(y));

        int minRow = x, minCol = y;
        int maxRow = x, maxCol = y;

        while (!stack.empty())
        {
            auto current = stack.top();
            stack.pop();
            int curX = current.first, curY = current.second;

            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto &dir : directions)
            {
                int nx = curX + dir.first;
                int ny = curY + dir.second;

                if (nx >= 0 && nx < land.size() && ny >= 0 && ny < land[0].size() &&
                    land[nx][ny] == 1 && visited.find(to_string(nx) + "," + to_string(ny)) == visited.end())
                {
                    visited.insert(to_string(nx) + "," + to_string(ny));
                    stack.push({nx, ny});
                    minRow = min(minRow, nx);
                    minCol = min(minCol, ny);
                    maxRow = max(maxRow, nx);
                    maxCol = max(maxCol, ny);
                }
            }
        }
        return {minRow, minCol, maxRow, maxCol};
    }
};

// For VSCode
int main()
{
    Solution o1;
    string seperator1 = "", seperator2 = "";
    vector<vector<int>> grid{{1, 0, 0}, {0, 1, 1}, {0, 1, 1}};
    vector<vector<int>> result = o1.findFarmland(grid);
    cout << "All Group of Farmland : [";
    for (auto x : result)
    {
        cout << seperator1 << "[";
        seperator1 = ",";
        for (auto y : x)
        {
            cout << seperator2 << y;
            seperator2 = ",";
        }
        cout << "]";
        seperator2 = "";
    }
    cout << "]" << endl;
    return 0;
}