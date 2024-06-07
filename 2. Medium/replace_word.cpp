// Leetcode problem statement link
// https://leetcode.com/problems/replace-words/

#include <bits/stdc++.h>
using namespace std;

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