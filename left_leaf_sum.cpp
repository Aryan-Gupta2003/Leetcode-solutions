// https://leetcode.com/problems/sum-of-left-leaves/

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
    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        queue<pair<TreeNode *, bool>> q;
        q.push({root, false});
        int totalSum = 0;

        while (!q.empty())
        {
            auto [node, isLeft] = q.front();
            q.pop();

            if (isLeft && !node->left && !node->right)
            {
                totalSum += node->val;
            }

            if (node->left)
            {
                q.push({node->left, true});
            }
            if (node->right)
            {
                q.push({node->right, false});
            }
        }

        return totalSum;
    }
};

int main()
{
    Solution o1;
    TreeNode *p = new TreeNode(3);
    p->left = new TreeNode(9);
    p->right = new TreeNode(20);
    p->right->left = new TreeNode(15);
    p->right->right = new TreeNode(7);

    int result = o1.sumOfLeftLeaves(p);
    cout << "Sum of Left Leaves : " << result << endl;

    return 0;
}