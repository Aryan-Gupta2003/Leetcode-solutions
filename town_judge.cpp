// Leetcode problem statement link
// https://leetcode.com/problems/find-the-town-judge/

// In a town, there are n people labeled from 1 to n. There
// is a rumor that one of these people is secretly the town judge.

// If the town judge exists, then:

// 1. The town judge trusts nobody.
// 2. Everybody (except for the town judge) trusts the town judge.
// 3. There is exactly one person that satisfies properties 1 and 2.
// 4. You are given an array trust where trust[i] = [ai, bi]
//    representing that the person labeled ai trusts the
//    person labeled bi. If a trust relationship does not exist
//    in trust array, then such a trust relationship does not exist.

// Return the label of the town judge if the town judge exists
// and can be identified, or return -1 otherwise.

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<pair<int, int>> a(n + 1, {0, 0});
        for (int i = 0; i < trust.size(); i++)
        {
            a[trust[i][0]].first += 1;
            a[trust[i][1]].second += 1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i].first == 0 && a[i].second == n - 1)
            {
                return i;
            }
        }
        return -1;
    }
};

// For VSCode
int main()
{
    Solution o1;
    int n = 3;
    vector<vector<int>> trust{{1, 3}, {2, 3}, {3, 1}};
    int result = o1.findJudge(n, trust);
    cout << "Town Judge : " << result << endl;
    return 0;
}