// Leetcode problem statement link
// https://leetcode.com/problems/replace-words/

// In English, we have a concept called root, which
// can be followed by some other word to form another
// longer word - let's call this word derivative.
// For example, when the root "help" is followed by
// the word "ful", we can form a derivative "helpful".

// Given a dictionary consisting of many roots and a
// sentence consisting of words separated by spaces,
// replace all the derivatives in the sentence with
// the root forming it. If a derivative can be replaced
// by more than one root, replace it with the root
// that has the shortest length.

// Return the sentence after the replacement.

#include <bits/stdc++.h>
using namespace std;

// Sol For Leetcode
class Trie
{
public:
    Trie *children[26];
    bool isEnd;
    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
        isEnd = false;
    }
};

class Solution
{
private:
    Trie *root;
    void insert(string word)
    {
        Trie *node = root;
        for (char c : word)
        {
            int i = c - 'a';
            if (node->children[i] == nullptr)
            {
                node->children[i] = new Trie();
            }
            node = node->children[i];
        }
        node->isEnd = true;
    }

    string search(string word)
    {
        Trie *node = root;
        string result;
        for (char c : word)
        {
            int i = c - 'a';
            if (node->children[i] == nullptr)
            {
                return word;
            }
            result += c;
            if (node->children[i]->isEnd)
            {
                return result;
            }
            node = node->children[i];
        }
        return word;
    }

public:
    Solution()
    {
        root = new Trie();
    }

    string replaceWords(vector<string> &dictionary, string sentence)
    {
        for (string word : dictionary)
        {
            insert(word);
        }

        stringstream ss(sentence);
        string word, result;
        while (ss >> word)
        {
            if (!result.empty())
            {
                result += " ";
            }
            result += search(word);
        }
        return result;
    }
};

// For VSCode
int main()
{
    Solution o1;
    vector<string> dictionary{"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    cout << "Sentence : " << sentence << endl;
    string result = o1.replaceWords(dictionary, sentence);
    cout << "New Sentence : " << result << endl;
    return 0;
}