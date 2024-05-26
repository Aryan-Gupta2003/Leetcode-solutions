// https://leetcode.com/problems/time-needed-to-buy-tickets/

// There are n people in a line queuing to
// buy tickets, where the 0th person is at
// the front of the line and the (n - 1)th
// person is at the back of the line.

// You are given a 0-indexed integer array
// tickets of length n where the number of
// tickets that the ith person would like
// to buy is tickets[i].

// Each person takes exactly 1 second to
// buy a ticket. A person can only buy 1
// ticket at a time and has to go back to
// the end of the line in order to buy more
// tickets. If a person does not have any tickets
// left to buy, the person will leave the line.

// Return the time taken for the person at
// position k (0-indexed) to finish buying tickets.

#include <bits/stdc++.h>
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
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int t = 0;
        while (tickets.size() != 0)
        {
            if (tickets[k] == 0)
            {
                t--;
                break;
            }
            if (tickets[0] > 0)
            {
                tickets[0] = tickets[0] - 1;
            }
            if (tickets[0] <= 0)
            {
                t++;
                if (tickets[k] == 0)
                    break;
                tickets.erase(tickets.begin());
                k--;
                if (k < 0)
                    k = tickets.size() - 1;
            }
            else
            {
                t++;
                if (tickets[k] == 0)
                    break;
                tickets.push_back(tickets[0]);
                tickets.erase(tickets.begin());
                k--;
                if (k < 0)
                    k = tickets.size() - 1;
            }
        }
        return (t < 0 ? 0 : t);
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> tickets{2, 3, 2};
    int k = 2;
    int result = o1.timeRequiredToBuy(tickets, k);
    cout << "Time Needed to Buy Tickets : " << result << endl;
    return 0;
}