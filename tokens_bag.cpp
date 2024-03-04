#include <bits/stdc++.h>
using namespace std;

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

int main()
{
    Solution o1;
    vector<int> tokens{100, 200, 300, 400};
    int power = 200;
    int result = o1.bagOfTokensScore(tokens, power);
    cout << "Maximum Score : " << result << endl;
    return 0;
}