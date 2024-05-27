// https://leetcode.com/problems/relative-ranks/

// You are given an integer array score
// of size n, where score[i] is the score
// of the ith athlete in a competition.
// All the scores are guaranteed to be unique.

// The athletes are placed based on their
// scores, where the 1st place athlete has the
// highest score, the 2nd place athlete has
// the 2nd highest score, and so on. The placement
// of each athlete determines their rank:

// The 1st place athlete's rank is "Gold Medal".
// The 2nd place athlete's rank is "Silver Medal".
// The 3rd place athlete's rank is "Bronze Medal".
// For the 4th place to the nth place athlete,
// their rank is their placement number (i.e.,
// the xth place athlete's rank is "x").
// Return an array answer of size n where answer[i]
// is the rank of the ith athlete.

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
    vector<string> findRelativeRanks(vector<int> &score)
    {
        vector<int> sortedScore = score;
        sort(sortedScore.begin(), sortedScore.end(), greater<int>());
        vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
        unordered_map<int, string> rankMapping;
        for (int i = 0; i < sortedScore.size(); i++)
        {
            if (i < 3)
            {
                rankMapping[sortedScore[i]] = medals[i];
            }
            else
            {
                rankMapping[sortedScore[i]] = to_string(i + 1);
            }
        }
        vector<string> result;
        for (int s : score)
        {
            result.push_back(rankMapping[s]);
        }
        return result;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> score{5, 4, 3, 2, 1};
    vector<string> result = o1.findRelativeRanks(score);
    string sep = "";
    cout << "Rank : [";
    for (auto x : result)
    {
        cout << sep << x;
        sep = ", ";
    }
    cout << "]" << endl;
    return 0;
}