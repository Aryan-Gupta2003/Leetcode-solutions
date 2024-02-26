// Leetcode problem statement link
// https://leetcode.com/problems/same-tree/

// Given the roots of two binary trees p and
// q, write a function to check if they are
// the same or not.

// Two binary trees are considered the same
// if they are structurally identical, and
// the nodes have the same value.

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// For VSCode
int main()
{
    Solution o1;
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode *q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    bool result = o1.isSameTree(p, q);
    cout << "Trees are same? " << (result ? "Yes" : "No") << endl;
    return 0;
}