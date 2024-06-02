// Leetcode problem statement link
// https://leetcode.com/problems/boats-to-save-people/

// You are given an array people where people[i]
// is the weight of the ith person, and an infinite
// number of boats where each boat can carry a
// maximum weight of limit. Each boat carries at
// most two people at the same time, provided the
// sum of the weight of those people is at most limit.

// Return the minimum number of boats to carry
// every given person.

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
    int numRescueBoats(vector<int> &people, int limit)
    {
        unsigned freq[30001] = {0};
        int maxW = 0, minW = 30001;
        for (int x : people)
        {
            freq[x]++;
            maxW = max(maxW, x);
            minW = min(minW, x);
        }
        for (int i = minW, j = 0; i <= maxW; i++)
        {
            int f = freq[i];
            fill(people.begin() + j, people.begin() + j + f, i);
            j += f;
        }
        int x = 0;
        for (int l = 0, r = people.size() - 1; l <= r; r--)
        {
            x++;
            if (people[l] + people[r] <= limit)
                l++;
        }
        return x;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> people{3, 2, 2, 1};
    int limit = 3;
    int result = o1.numRescueBoats(people, limit);
    cout << "Min no. of boats to carry every given person : "
         << result << endl;
    return 0;
}