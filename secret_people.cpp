#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson)
    {
        unordered_map<int, vector<pair<int, int>>> graph;
        for (auto &meeting : meetings)
        {
            int x = meeting[0], y = meeting[1], t = meeting[2];
            graph[x].emplace_back(t, y);
            graph[y].emplace_back(t, x);
        }

        vector<int> v(n, INT_MAX);
        v[0] = 0;
        v[firstPerson] = 0;

        queue<pair<int, int>> q;
        q.emplace(0, 0);
        q.emplace(firstPerson, 0);

        while (!q.empty())
        {
            auto [person, time] = q.front();
            q.pop();
            for (auto [t, nextPerson] : graph[person])
            {
                if (t >= time && v[nextPerson] > t)
                {
                    v[nextPerson] = t;
                    q.emplace(nextPerson, t);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i)
        {
            if (v[i] != INT_MAX)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
    Solution o1;
    int n = 5, firdtPerson = 1;
    vector<vector<int>> meetings{{3, 4, 2}, {1, 2, 1}, {2, 3, 1}};
    vector<int> result = o1.findAllPeople(n, meetings, firdtPerson);
    for (auto x : result)
        cout << " " << x;
    cout << endl;
    return 0;
}
