#include <iostream>
#include <vector>
#include <string>
using namespace std;

// TrieNode represents a node in the trie
class TrieNode
{
public:
    TrieNode *children[26]; // Array of pointers for each alphabet character
    bool isEnd;             // Flag to mark if a node represents the end of a word

    // Constructor initializes all children to nullptr and isEnd to false
    TrieNode()
    {
        isEnd = false;
        for (auto &child : children)
            child = nullptr;
    }
};

// Trie represents the trie data structure
class Trie
{
public:
    TrieNode *root; // Root node of the trie

    // Constructor initializes the root node
    Trie() : root(new TrieNode()) {}

    // Inserts a word into the trie
    void insert(const string &word)
    {
        TrieNode *cur = root;
        for (char c : word)
        {
            if (cur->children[c - 'a'] == nullptr)
            {
                cur->children[c - 'a'] = new TrieNode(); // Create a new node if it doesn't exist
            }
            cur = cur->children[c - 'a']; // Move to the next node
        }
        cur->isEnd = true; // Mark the end of the word
    }
};

// Solution class containing the method to find index pairs
class Solution
{
public:
    // Time complexity - O(N* L + T^2)
    // Space complexity - O(N*L)
    vector<vector<int>> indexPairs(const string &text, const vector<string> &words)
    {
        Trie trie;
        for (const string &word : words)
        {
            trie.insert(word); // Insert words into the trie
        }

        vector<vector<int>> result; // To store the resulting index pairs

        for (int i = 0; i < text.length(); i++)
        {
            TrieNode *p = trie.root;
            for (int j = i; j < text.length(); j++)
            {
                if (p->children[text[j] - 'a'] == nullptr)
                    break;

                p = p->children[text[j] - 'a'];

                if (p->isEnd)
                    result.push_back({i, j});
            }
        }

        return result;
    }
};

// Function to print the array of index pairs
void printIndexPairs(const vector<vector<int>> &pairs)
{
    for (const auto &pair : pairs)
    {
        cout << "[" << pair[0] << ", " << pair[1] << "] ";
    }
    cout << endl;
}

int main()
{
    Solution solution;
    // Test cases
    printIndexPairs(solution.indexPairs("bluebirdskyscraper", {"blue", "bird", "sky"}));
    printIndexPairs(solution.indexPairs("programmingisfun", {"pro", "is", "fun", "gram"}));
    printIndexPairs(solution.indexPairs("interstellar", {"stellar", "star", "inter"}));

    return 0;
}
