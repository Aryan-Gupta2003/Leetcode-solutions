// Leetcode problem statement link
// https://leetcode.com/problems/task-scheduler/

// You are given an array of CPU tasks, each represented
// by letters A to Z, and a cooling time, n. Each cycle
// or interval allows the completion of one task. Tasks
// can be completed in any order, but there's a constraint:
// identical tasks must be separated by at least n
// intervals due to cooling time.

// ​Return the minimum number of intervals required
// to complete all tasks.

#include <bits/stdc++.h>
using namespace std;

// Sol For leetcode
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        int l = tasks.size();
        if (n == 0)
            return l;
        else
        {
            int arr[26] = {0};
            for (auto x : tasks)
            {
                arr[x - 'A']++;
            }
            sort(begin(arr), end(arr), greater<char>());
            int space = arr[0] - 1;
            int idel = space * n;
            for (int i = 1; i < 26; i++)
                idel -= min(space, arr[i]);

            return (idel > 0 ? (l + idel) : l);
        }
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 3;
    int result = o1.leastInterval(tasks, n);
    cout << "Minimum number of intervals required to complete all tasks : " << result << endl;
    return 0;
}