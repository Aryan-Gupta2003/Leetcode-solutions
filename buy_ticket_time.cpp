// https://leetcode.com/problems/time-needed-to-buy-tickets/

#include <bits/stdc++.h>
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

int main()
{
    Solution o1;
    vector<int> tickets{2, 3, 2};
    int k = 2;
    int result = o1.timeRequiredToBuy(tickets, k);
    cout << "Time Needed to Buy Tickets : " << result << endl;
    return 0;
}