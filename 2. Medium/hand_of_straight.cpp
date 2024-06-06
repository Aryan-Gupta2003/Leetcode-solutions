// Leetcode problem statement link
// https://leetcode.com/problems/hand-of-straights/

// Alice has some number of cards and she wants to
// rearrange the cards into groups so that each
// group is of size groupSize, and consists of
// groupSize consecutive cards.

// Given an integer array hand where hand[i] is the
// value written on the ith card and an integer
// groupSize, return true if she can rearrange the
// cards, or false otherwise.

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
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;

        unordered_map<int, int> count;
        for (int card : hand)
            count[card]++;

        vector<int> sortedKeys;
        for (auto &pair : count)
            sortedKeys.push_back(pair.first);

        sort(sortedKeys.begin(), sortedKeys.end());
        for (int key : sortedKeys)
        {
            if (count[key] > 0)
            {
                int startCount = count[key];
                for (int i = key; i < key + groupSize; i++)
                {
                    if (count[i] < startCount)
                    {
                        return false;
                    }
                    count[i] -= startCount;
                }
            }
        }
        return true;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> hand{1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize = 3;
    bool result = o1.isNStraightHand(hand, groupSize);
    cout << "Rearranged Cards : " << (result == 1 ? "True" : "False");
    return 0;
}