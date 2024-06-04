// Leetcode problem statement link
// https://leetcode.com/problems/open-the-lock/

// You have a lock in front of you with 4
// circular wheels. Each wheel has 10 slots:
// '0', '1', '2', '3', '4', '5', '6', '7',
// '8', '9'. The wheels can rotate freely and
// wrap around: for example we can turn '9'
// to be '0', or '0' to be '9'. Each move
// consists of turning one wheel one slot.

// The lock initially starts at '0000', a
// string representing the state of the 4 wheels.

// You are given a list of deadends dead ends,
// meaning if the lock displays any of these
// codes, the wheels of the lock will stop
// turning and you will be unable to open it.

// Given a target representing the value of the
// wheels that will unlock the lock, return the
// minimum total number of turns required to open
// the lock, or -1 if it is impossible.

#include <bits/stdc++.h>
#include <unordered_set>
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

// For VSCode
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