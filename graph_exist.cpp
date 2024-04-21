// https://leetcode.com/problems/find-if-path-exists-in-graph/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        unordered_map<int, vector<int>> graph;
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        unordered_set<int> visited;
        return dfs(source, destination, graph, visited);
    }

    bool dfs(int node, int destination, unordered_map<int, vector<int>> &graph, unordered_set<int> &visited)
    {
        if (node == destination)
        {
            return true;
        }
        visited.insert(node);
        for (int neighbor : graph[node])
        {
            if (visited.find(neighbor) == visited.end())
            {
                if (dfs(neighbor, destination, graph, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution o1;
    int n = 3, source = 0, destination = 2;
    vector<vector<int>> edges{{0, 1}, {1, 2}, {2, 0}};
    bool result = o1.validPath(n, edges, source, destination);
    cout << "Path Exists in Graph : " << (result == 1 ? "True" : "false") << endl;
    return 0;
}