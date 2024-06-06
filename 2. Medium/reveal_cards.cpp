// Leetcode problem statement link
// https://leetcode.com/problems/reveal-cards-in-increasing-order/

// You are given an integer array deck. There is
// a deck ofcards where every card has a unique
// integer. The integer on the ith card is deck[i].

// You can order the deck in any order you want. Initially,
// all the cards start face down (unrevealed) in one deck.

// You will do the following steps repeatedly
// until all cards are revealed:
// Take the top card of the deck, reveal it,
// and take it out of the deck.
// If there are still cards in the deck then put the
// next top card of the deck at the bottom of the deck.
// If there are still unrevealed cards, go back to
// step 1. Otherwise, stop.
// Return an ordering of the deck that
// would reveal the cards in increasing order.

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

// For VSCode
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