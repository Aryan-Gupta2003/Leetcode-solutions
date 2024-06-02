// Leetcode problem statement link
// https://leetcode.com/problems/sum-of-distances-in-tree/

// There is an undirected connected tree with n
// nodes labeled from 0 to n - 1 and n - 1 edges.

// You are given the integer n and the array
// edges where edges[i] = [ai, bi] indicates
// that there is an edge between nodes ai and
// bi in the tree.

// Return an array answer of length n where
// answer[i] is the sum of the distances
// between the ith node in the tree and all
// other nodes.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
private:
    unordered_map<int, vector<int>> graph;
    vector<int> count;
    vector<int> res;

    void dfs(int node, int parent)
    {
        for (int child : graph[node])
        {
            if (child != parent)
            {
                dfs(child, node);
                count[node] += count[child];
                res[node] += res[child] + count[child];
            }
        }
    }

    void dfs2(int node, int parent)
    {
        for (int child : graph[node])
        {
            if (child != parent)
            {
                res[child] = res[node] - count[child] + (count.size() - count[child]);
                dfs2(child, node);
            }
        }
    }

public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        graph.clear();
        count = vector<int>(n, 1);
        res = vector<int>(n, 0);

        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs(0, -1);
        dfs2(0, -1);

        return res;
    }
};

// For VSCode
int main()
{
    Solution o1;
    int n = 6;
    string sep = "";
    vector<vector<int>> edges{{0, 1}, {0, 2}, {2, 3}, {2, 4}, {2, 5}};
    vector<int> result = o1.sumOfDistancesInTree(n, edges);
    cout << "Sum of Distances in Tree : [";
    for (int x : result)
    {
        cout << sep << x;
        sep = ", ";
    }
    cout << "]" << endl;
    return 0;
}