// Leetcode problem statement link
// https://leetcode.com/problems/meeting-rooms-iii/

// Given an integer n. There are n rooms numbered from 0 to
// n - 1 and 2D integer array meetings where meetings[i] = [starti, endi]
// means that a meeting will be held during the half-closed
// time interval [starti, endi). All the values of starti are unique.

// Meetings are allocated to rooms in the following manner:

// 1. Each meeting will take place in the unused room with the lowest number.
// 2. If there are no available rooms, the meeting will be delayed until a room
//    becomes free. The delayed meeting should have the same duration as the original meeting.
// 3. When a room becomes unused, meetings that have an earlier original
//    start time should be given the room.

// Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

// A half-closed interval [a, b) is the interval between a and b including a and not including b.

#include <bits/stdc++.h>
#include <queue>
using namespace std;

// Sol for Leetcode
class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        vector<int> mc(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> used;
        priority_queue<int, vector<int>, greater<int>> unused;
        for (int i = 0; i < n; i++)
        {
            unused.push(i);
        }
        sort(meetings.begin(), meetings.end());

        for (auto x : meetings)
        {
            int start = x[0], end = x[1];

            while (!used.empty() && used.top().first <= start)
            {
                int r = used.top().second;
                used.pop();
                unused.push(r);
            }
            if (!unused.empty())
            {
                int r = unused.top();
                unused.pop();
                used.push({end, r});
                mc[r]++;
            }
            else
            {
                int rAvailT = used.top().first, r = used.top().second;
                used.pop();
                used.push({rAvailT + end - start, r});
                mc[r]++;
            }
        }

        int mMeetC = 0, mMeetCR = 0;
        for (int i = 0; i < n; i++)
        {
            if (mc[i] > mMeetC)
            {
                mMeetC = mc[i];
                mMeetCR = i;
            }
        }
        return mMeetCR;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<vector<int>> meetings{{1, 20}, {2, 10}, {3, 5}, {4, 9}, {6, 7}};
    int n = 3;
    int result = o1.mostBooked(n, meetings);
    cout << "No. of rooms that held the most meeetings : " << result << endl;
    return 0;
}