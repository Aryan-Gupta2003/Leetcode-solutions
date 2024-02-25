// Leetcode problem statement link
// https://leetcode.com/problems/find-all-people-with-secret/

// You are given an integer n indicating there are n people
// numbered from 0 to n - 1. You are also given a 0-indexed
// 2D integer array meetings where meetings[i] = [xi, yi, timei]
// indicates that person xi and person yi have a meeting at timei.
// A person may attend multiple meetings at the same time. Finally,
// you are given an integer firstPerson.

// Person 0 has a secret and initially shares the secret with a
// person firstPerson at time 0. This secret is then shared every
// time a meeting takes place with a person that has the secret.
// More formally, for every meeting, if a person xi has the secret at
// timei, then they will share the secret with person yi, and vice versa.

// The secrets are shared instantaneously. That is, a person may
// receive the secret and share it with people in other meetings
// within the same time frame.

// Return a list of all the people that have the secret after all
// the meetings have taken place. You may return the answer in any order.

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode
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

// For VSCode
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
