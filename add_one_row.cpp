// https://leetcode.com/problems/add-one-row-to-tree/

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