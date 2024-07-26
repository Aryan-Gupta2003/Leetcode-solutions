// Leetcode problem statement link
// https://leetcode.com/problems/word-search/

// Given an m x n grid of characters board and a
// string word, return true if word exists in the grid.

// The word can be constructed from letters of
// sequentially adjacent cells, where adjacent
// cells are horizontally or vertically neighboring.
// The same letter cell may not be used more than once.

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
    bool exist(vector<vector<char>> &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        function<bool(int, int, int)> b = [&](int i, int j, int k)
        {
            if (k == word.length())
            {
                return true;
            }
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k])
            {
                return false;
            }

            char temp = board[i][j];
            board[i][j] = '\0';

            if (b(i + 1, j, k + 1) || b(i - 1, j, k + 1) ||
                b(i, j + 1, k + 1) || b(i, j - 1, k + 1))
            {
                return true;
            }

            board[i][j] = temp;
            return false;
        };

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (b(i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    bool result = o1.exist(board, word);
    cout << "Word Found : " << (result == 1 ? "True" : "False") << endl;
    return 0;
}