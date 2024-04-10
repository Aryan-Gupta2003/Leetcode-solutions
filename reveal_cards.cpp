// https://leetcode.com/problems/reveal-cards-in-increasing-order/

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
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        vector<int> arr(n);
        deque<int> dq;

        for (int i = 0; i < n; i++)
        {
            dq.push_back(i);
        }

        for (int x : deck)
        {
            int i = dq.front();
            dq.pop_front();
            arr[i] = x;
            if (!dq.empty())
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        return arr;
    }
};

int main()
{
    Solution o1;
    vector<int> deck{17, 13, 11, 2, 3, 5, 7};
    vector<int> result = o1.deckRevealedIncreasing(deck);
    cout << "Ordering Deck : ";
    for (int x : result)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}