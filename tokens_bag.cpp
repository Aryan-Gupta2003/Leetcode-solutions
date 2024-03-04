// Leetcode problem statement link
// https://leetcode.com/problems/bag-of-tokens/

// You start with an initial power of power,
// an initial score of 0, and a bag of tokens
// given as an integer array tokens, where
// each tokens[i] donates the value of tokeni.

// Your goal is to maximize the total score by
// strategically playing these tokens. In one
// move, you can play an unplayed token in one
// of the two ways (but not both for the same token):

// 1. Face-up: If your current power is at least
//    tokens[i], you may play tokeni, losing
//    tokens[i] power and gaining 1 score.
// 2. Face-down: If your current score is at least
//    1, you may play tokeni, gaining tokens[i]
//    power and losing 1 score.

// Return the maximum possible score you can achieve after playing any number of tokens.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int score = 0;
        int maxscore = 0;
        int i = 0, l = tokens.size() - 1;
        while (i <= l)
        {
            if (power >= tokens[i])
            {
                power -= tokens[i];
                score++;
                i++;
                maxscore = max(maxscore, score);
            }
            else if (score > 0)
            {
                power += tokens[l];
                score--;
                l--;
            }
            else
            {
                break;
            }
        }

        return maxscore;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<int> tokens{100, 200, 300, 400};
    int power = 200;
    int result = o1.bagOfTokensScore(tokens, power);
    cout << "Maximum Score : " << result << endl;
    return 0;
}