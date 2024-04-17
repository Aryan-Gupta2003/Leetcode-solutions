// https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    void dfs(TreeNode *root, string path, string &ans)
    {
        if (!root)
            return;

        path += char('a' + root->val);

        if (!root->left && !root->right)
        {
            reverse(path.begin(), path.end());
            if (ans.empty() || path < ans)
            {
                ans = path;
            }
            reverse(path.begin(), path.end());
        }

        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }

    string smallestFromLeaf(TreeNode *root)
    {
        string a;
        dfs(root, "", a);
        return a;
    }
};

int main()
{
    Solution o1;
    TreeNode *p = new TreeNode(0);
    p->left = new TreeNode(1);
    p->right = new TreeNode(2);
    p->left->left = new TreeNode(3);
    p->left->right = new TreeNode(4);
    p->right->left = new TreeNode(3);
    p->right->right = new TreeNode(4);

    string result = o1.smallestFromLeaf(p);
    cout << "Smallest String Starting From Leaf : " << result << endl;
    return 0;
}