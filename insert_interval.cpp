#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> m;
        int i = 0;

        while (i < intervals.size() && intervals[i][1] < newInterval[0])
        {
            m.push_back(intervals[i]);
            i++;
        }

        while (i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            i++;
        }
        m.push_back(newInterval);

        while (i < intervals.size())
        {
            m.push_back(intervals[i]);
            i++;
        }

        return m;
    }
};

int main()
{
    Solution o1;
    vector<vector<int>> nums{{1, 3}, {6, 9}};
    vector<int> newnums{2, 5};
    vector<vector<int>> result = o1.insert(nums, newnums);
    cout << "Intervals after the insertion : [";
    string seperator1;
    for (auto x : result)
    {
        string seperator2;
        cout << seperator1 << "[";
        for (auto y : x)
        {
            cout << seperator2 << y;
            seperator2 = ",";
        }
        cout << "]";
        seperator1 = ", ";
    }
    cout << "]" << endl;

    return 0;
}