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
    void leftmost(TreeNode *node, int c, int &d, int &l)
    {
        if (node == nullptr)
        {
            return;
        }
        if (c > d)
        {
            d = c;
            l = node->val;
        }
        leftmost(node->left, c + 1, d, l);
        leftmost(node->right, c + 1, d, l);
    }
    int findBottomLeftValue(TreeNode *root)
    {
        int d = 0, l = 0;
        leftmost(root, 1, d, l);
        return l;
    }
};

int main()
{
    Solution o1;
    TreeNode *p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    int result = o1.findBottomLeftValue(p);
    cout << "Largest Diameter : " << result << endl;

    return 0;
}