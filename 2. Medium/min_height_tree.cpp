// Leetcode problem statement link
// https://leetcode.com/problems/minimum-height-trees/

// A tree is an undirected graph in which any two
// vertices are connected by exactly one path. In
// other words, any connected graph without simple
// cycles is a tree.
// Given a tree of n nodes labelled from 0 to n - 1,
// and an array of n - 1 edges where edges[i] = [ai,
// bi] indicates that there is an undirected edge
// between the two nodes ai and bi in the tree, you
// can choose any node of the tree as the root. When
// you select a node x as the root, the result tree
// has height h. Among all possible rooted trees,
// those with minimum height (i.e. min(h))  are called
// minimum height trees (MHTs).

// Return a list of all MHTs' root labels. You can return
// the answer in any order.
// The height of a rooted tree is the number of edges on
// the longest downward path between the root and a leaf.

#include <bits/stdc++.h>
using namespace std;

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
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
        {
            return {0}; // Only one node, return the root
        }

        unordered_map<int, vector<int>> graph;
        vector<int> degrees(n, 0);

        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            degrees[u]++;
            degrees[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (degrees[i] == 1)
            {
                q.push(i);
            }
        }

        int remainingNodes = n;
        while (remainingNodes > 2)
        {
            int size = q.size();
            remainingNodes -= size;

            for (int i = 0; i < size; i++)
            {
                int leaf = q.front();
                q.pop();
                for (int neighbor : graph[leaf])
                {
                    degrees[neighbor]--;
                    if (degrees[neighbor] == 1)
                    {
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> result;
        while (!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
};

// For VSCode
int main()
{
    Solution o1;
    int n = 3;
    string seperator = "";
    vector<vector<int>> edges{{0, 1}, {1, 2}, {1, 3}};
    vector<int> result = o1.findMinHeightTrees(n, edges);
    cout << "Minimum Height Trees : [";
    for (auto x : result)
    {
        cout << seperator << x;
        seperator = ",";
    }
    cout << "]" << endl;
    return 0;
}