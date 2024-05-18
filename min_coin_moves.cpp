// https://leetcode.com/problems/distribute-coins-in-binary-tree/

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

class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    int minmoves(TreeNode *root, TreeNode *parent)
    {
        if (root == nullptr)
            return 0;
        int moves = minmoves(root->left, root) + minmoves(root->right, root);
        int x = root->val - 1;
        if (parent != nullptr)
            parent->val += x;
        moves += abs(x);
        return moves;
    }

    int distributeCoins(TreeNode *root)
    {
        return minmoves(root, NULL);
    }
};

int main()
{
    Solution o1;
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(3);
    root->right = new TreeNode(0);
    int result = o1.distributeCoins(root);
    cout << "Minimum number of moves : " << result << endl;
    return 0;
}