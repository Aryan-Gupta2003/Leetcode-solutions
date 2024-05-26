// Leetcode problem statement link
// https://leetcode.com/problems/delete-leaves-with-a-given-value/

// Given a binary tree root and an integer
// target, delete all the leaf nodes with
// value target.

// Note that once you delete a leaf node
// with value target, if its parent node
// becomes a leaf node and has the value
// target, it should also be deleted (you
// need to continue doing that until you cannot).

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
    TreeNode *removeLeafNodes(TreeNode *root, int target)
    {
        if (root == nullptr)
            return nullptr;
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (!root->left && !root->right && root->val == target)
            return nullptr;
        return root;
    }
};

// For VSCode
void printTree(TreeNode *root)
{
    if (!root)
    {
        cout << "null";
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node)
        {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
        else
        {
            cout << "null ";
        }
    }
    cout << endl;
}

int main()
{
    Solution o1;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(2), new TreeNode(4));
    root->right = new TreeNode(3, new TreeNode(2), new TreeNode(5));

    cout << "Original tree (in-order): ";
    printTree(root);
    cout << endl;

    int target = 2;
    root = o1.removeLeafNodes(root, target);

    cout << "Tree after removing leaf nodes with value " << target << " (in-order): ";
    printTree(root);
    cout << endl;
    return 0;
}