// Leetcode problem statement link
// https://leetcode.com/problems/even-odd-tree/

// A binary tree is named Even-Odd if it
// meets the following conditions:

// 1. The root of the binary tree is at level
// index 0, its children are at level index 1,
// their children are at level index 2, etc.
// 2. For every even-indexed level, all nodes
// at the level have odd integer values in
// strictly increasing order (from left to right).
// 3. For every odd-indexed level, all nodes at
// the level have even integer values in strictly
// decreasing order (from left to right).

// Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

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
private:
    vector<int> prev;

public:
    bool evenodd(TreeNode *node, size_t l)
    {
        if (node == nullptr)
        {
            return true;
        }

        if (node->val % 2 == l % 2)
        {
            return false;
        }

        prev.resize(max(prev.size(), l + 1));

        if (prev[l] != 0 && ((l % 2 == 0 && node->val <= prev[l]) || (l % 2 == 1 && node->val >= prev[l])))
        {
            return false;
        }

        prev[l] = node->val;

        return evenodd(node->left, l + 1) && evenodd(node->right, l + 1);
    }
    bool isEvenOddTree(TreeNode *root)
    {
        TreeNode *c = root;
        return evenodd(c, 0);
    }
};

// For VSCode
TreeNode *initializeTree()
{
    auto newNode = [](int val)
    {
        return new TreeNode(val);
    };

    TreeNode *root = newNode(1);
    root->left = newNode(4);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(7);
    root->right->right = newNode(9);

    return root;
}

int main()
{
    Solution o1;
    TreeNode *p = initializeTree();
    bool result = o1.isEvenOddTree(p);
    cout << "Even-Odd Tree are not ? " << (result ? "Yes" : "No") << endl;
    return 0;
}