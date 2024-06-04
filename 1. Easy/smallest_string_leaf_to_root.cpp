// Leetcode problem statement link
// https://leetcode.com/problems/smallest-string-starting-from-leaf/

// You are given row x col grid representing a
// map where grid[i][j] = 1 represents land and
// grid[i][j] = 0 represents water.

// Grid cells are connected horizontally/vertically
// (not diagonally). The grid is completely surrounded
// by water, and there is exactly one island (i.e.,
// one or more connected land cells).

// The island doesn't have "lakes", meaning the water
// inside isn't connected to the water around the island.
// One cell is a square with side length 1. The grid is
// rectangular, width and height don't exceed 100.
// Determine the perimeter of the island.

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    void dfs(TreeNode *root, string path, string &ans)
    {
        if (!root)
            return;

        path += char('a' + root->val);

        if (!root->left && !root->right)
        {
            reverse(path.begin(), path.end());
            if (ans.empty() || path < ans)
            {
                ans = path;
            }
            reverse(path.begin(), path.end());
        }

        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }

    string smallestFromLeaf(TreeNode *root)
    {
        string a;
        dfs(root, "", a);
        return a;
    }
};

// For VSCode
int main()
{
    Solution o1;
    TreeNode *p = new TreeNode(0);
    p->left = new TreeNode(1);
    p->right = new TreeNode(2);
    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(4);
    p->right->left = new TreeNode(3);
    p->right->right = new TreeNode(4);

    string result = o1.smallestFromLeaf(p);
    cout << "Smallest String Starting From Leaf : " << result << endl;
    return 0;
}