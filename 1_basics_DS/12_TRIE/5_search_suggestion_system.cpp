#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TrieNode
{
public:
    TrieNode *children[26] = {nullptr}; // Pointers to child nodes for each alphabet character.
    bool isEnd = false;                 // Flag to mark the end of a word.
};

class Trie
{
private:
    TrieNode *root;
    //    Time complexity - (M + K) - size of array + time taken by dfs
    void dfs(TrieNode *node, vector<string> &list, string word, int &count)
    {
        // Base case
        if (list.size() == 3)
            return;
        if (node->isEnd)
            list.push_back(word);

        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            if (node->children[ch - 'a'] != nullptr)
                dfs(node->children[ch - 'a'], list, word + ch, count);
        }
    }

public:
    Trie() : root(new TrieNode()) {}

    // Insert into Trie
    void insert(const string word)
    {
        TrieNode *node = root;
        for (char ch : word)
        {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }
        node->isEnd = true;
    }

    vector<string> search(const string prefix)
    {
        vector<string> list;
        TrieNode *node = root;

        for (auto ch : prefix)
        {
            if (node->children[ch - 'a'] == nullptr)
                return list;

            node = node->children[ch - 'a'];
        }

        int count = 0;

        dfs(node, list, prefix, count);
        return list;
    }
};

class Solution
{
public:
    // Time Complexity - O(N*L + M) - no of products and length of each product
    // Space complexity - O(N*L)
    vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
    {
        Trie trie;

        for (auto product : products)
            trie.insert(product);

        vector<vector<string>> result;
        string prefix = "";

        for (char ch : searchWord)
        {
            prefix += ch;
            result.push_back(trie.search(prefix));
        }

        return result;
    }
};

int main()
{
    Solution solution;

    vector<string> products1 = {"apple", "apricot", "application"};
    string searchWord1 = "app";

    vector<string> products2 = {"king", "kingdom", "kit"};
    string searchWord2 = "ki";

    vector<string> products3 = {"fantasy", "fast", "festival"};
    string searchWord3 = "farm";

    // Test Example 1
    vector<vector<string>> result1 = solution.suggestedProducts(products1, searchWord1);
    cout << "Example 1: ";
    for (auto &list : result1)
    {
        for (auto &word : list)
            cout << word << " ";
        cout << endl;
    }

    // // Test Example 2
    // vector<vector<string>> result2 = solution.suggestedProducts(products2, searchWord2);
    // cout << "Example 2: ";
    // for (auto &list : result2)
    // {
    //     for (auto &word : list)
    //         cout << word << " ";
    //     cout << endl;
    // }

    // // Test Example 3
    // vector<vector<string>> result3 = solution.suggestedProducts(products3, searchWord3);
    // cout << "Example 3: ";
    // for (auto &list : result3)
    // {
    //     for (auto &word : list)
    //         cout << word << " ";
    //     cout << endl;
    // }

    return 0;
}
