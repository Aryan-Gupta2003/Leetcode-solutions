// https://leetcode.com/problems/relative-ranks/

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