// https://leetcode.com/problems/open-the-lock/

#include <bits/stdc++.h>
#include <unordered_set>
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
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> dSet(deadends.begin(), deadends.end());
        if (dSet.count("0000"))
        {
            return -1;
        }

        queue<pair<string, int>> queue;
        queue.push({"0000", 0});
        unordered_set<string> visited;
        visited.insert("0000");

        while (!queue.empty())
        {
            auto c = queue.front();
            queue.pop();
            string cCombination = c.first;
            int m = c.second;

            if (cCombination == target)
            {
                return m;
            }

            for (int i = 0; i < 4; i++)
            {
                for (int d : {-1, 1})
                {
                    int newDigit = (cCombination[i] - '0' + d + 10) % 10;
                    string newCombination = cCombination;
                    newCombination[i] = '0' + newDigit;

                    if (visited.find(newCombination) == visited.end() && dSet.find(newCombination) == dSet.end())
                    {
                        visited.insert(newCombination);
                        queue.push({newCombination, m + 1});
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    Solution o1;
    vector<string> deadends{"0201", "0101", "0102", "1212", "2002"};
    string target = "0202";
    int result = o1.openLock(deadends, target);
    cout << "Minimum total number of turns required to open the lock : "
         << result << endl;
    return 0;
}