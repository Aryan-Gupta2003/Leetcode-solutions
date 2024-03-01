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