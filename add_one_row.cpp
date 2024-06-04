// Leetcode problem statement link
// https://leetcode.com/problems/add-one-row-to-tree/

// Given the root of a binary tree and two integers
// val and depth, add a row of nodes with value val
// at the given depth depth.
// Note that the root node is at depth 1.

// The adding rule is:
// Given the integer depth, for each not null tree
// node cur at the depth depth - 1, create two tree
// nodes with value val as cur's left subtree root
// and right subtree root.
// cur's original left subtree should be the left
// subtree of the new left subtree root.
// cur's original right subtree should be the right
// subtree of the new right subtree root.
// If depth == 1 that means there is no depth depth
// - 1 at all, then create a tree node with value
// val as the new root of the whole original tree,
// and the original tree is the new root's left subtree.

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
    TreeNode *add(TreeNode *root, int val, int depth, int curr)
    {
        if (!root)
            return nullptr;

        if (curr == depth - 1)
        {
            TreeNode *l = root->left;
            TreeNode *r = root->right;

            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = l;
            root->right->right = r;

            return root;
        }

        root->left = add(root->left, val, depth, curr + 1);
        root->right = add(root->right, val, depth, curr + 1);

        return root;
    }
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *n = new TreeNode(val);
            n->left = root;
            return n;
        }
        return add(root, val, depth, 1);
    }
};

// For VSCode
void printTree(TreeNode *root)
{
    if (!root)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node)
        {
            cout << node->val << " ";
            if (node->left || node->right)
            {
                if (node->left)
                    q.push(node->left);
                else
                    q.push(nullptr);
                if (node->right)
                    q.push(node->right);
                else
                    q.push(nullptr);
            }
        }
        else
        {
            cout << "null ";
        }
    }
}

int main()
{
    Solution o1;
    TreeNode *p = new TreeNode(4);
    p->left = new TreeNode(2);
    p->right = new TreeNode(6);
    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(1);
    p->right->left = new TreeNode(5);

    int val = 1, depth = 2;
    TreeNode *result = o1.addOneRow(p, val, depth);
    cout << "New Tree : ";
    printTree(result);
    return 0;
}