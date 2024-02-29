// Leetcode problem statement link
// https://leetcode.com/problems/diameter-of-binary-tree/

// Given the root of a binary tree, return
// the length of the diameter of the tree.

// The diameter of a binary tree is the length of
// the longest path between any two nodes in a tree.
// This path may or may not pass through the root.

// The length of a path between two nodes is
// represented by the number of edges between them.

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

// Sol for Leetcode
class Solution
{
public:
    int height(TreeNode *node)
    {
        if (node == nullptr)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l_height = height(root->left);
        int r_height = height(root->right);

        int l_diameter = diameterOfBinaryTree(root->left);
        int r_diameter = diameterOfBinaryTree(root->right);

        return max({l_height + r_height, l_diameter, r_diameter});
    }
};

// For VSCode
int main()
{
    Solution o1;
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    p->left->right = new TreeNode(5);

    int result = o1.diameterOfBinaryTree(p);
    cout << "Largest Diameter : " << result << endl;

    return 0;
}