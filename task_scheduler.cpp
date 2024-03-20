#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    Solution o1;
    vector<char> tasks{'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 3;
    int result = o1.leastInterval(tasks, n);
    cout << "Minimum number of intervals required to complete all tasks : " << result << endl;
    return 0;
}