// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int dfs(TreeNode *n, int sum)
    {
        if (n == nullptr)
        {
            return 0;
        }
        sum = sum * 10 + n->val;

        if (n->left == nullptr && n->right == nullptr)
        {
            return sum;
        }

        return (dfs(n->left, sum) + dfs(n->right, sum));
    }
    int sumNumbers(TreeNode *root)
    {
        return dfs(root, 0);
    }
};

int main()
{
    Solution o1;
    TreeNode *p = new TreeNode(4);
    p->left = new TreeNode(9);
    p->right = new TreeNode(0);
    p->left->left = new TreeNode(5);
    p->left->right = new TreeNode(1);

    int result = o1.sumNumbers(p);
    cout << "Sum of Root to Leaf numbers : " << result << endl;
    return 0;
}