// Leetcode problem statement link
// https://leetcode.com/problems/maximum-score-words-formed-by-letters/

// Given a list of words, list of  single
// letters (might be repeating) and score
// of every character.

// Return the maximum score of any valid set
// of words formed by using the given letters
// (words[i] cannot be used two or more times).

// It is not necessary to use all characters in letters
// and each letter can only be used once. Score of
// letters 'a', 'b', 'c', ... ,'z' is given by
// score[0], score[1], ... , score[25] respectively

#include <bits/stdc++.h>
using namespace std;

// Sol for Leetcode
class Solution
{
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        unordered_map<char, int> lettersCounter;
        for (char letter : letters)
        {
            lettersCounter[letter]++;
        }

        int totalScore = 0;

        function<void(int, unordered_map<char, int>, int)> explore =
            [&](int index, unordered_map<char, int> letterCounter, int currScore)
        {
            totalScore = max(totalScore, currScore);
            if (index == words.size())
                return;

            for (int i = index; i < words.size(); ++i)
            {
                unordered_map<char, int> tmpCounter = letterCounter;
                string word = words[i];
                int wordScore = 0;
                bool isValid = true;

                for (char ch : word)
                {
                    if (tmpCounter[ch] > 0)
                    {
                        tmpCounter[ch]--;
                        wordScore += score[ch - 'a'];
                    }
                    else
                    {
                        isValid = false;
                        break;
                    }
                }
                if (isValid)
                {
                    explore(i + 1, tmpCounter, currScore + wordScore);
                }
            }
        };

        explore(0, lettersCounter, 0);
        return totalScore;
    }
};

// For Vscode
int main()
{
    Solution o1;
    vector<string> words{"dog", "cat", "dad", "good"};
    vector<char> letters{'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    vector<int> score{1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int result = o1.maxScoreWords(words, letters, score);
    cout << "Maximum Score : " << result << endl;
    return 0;
}