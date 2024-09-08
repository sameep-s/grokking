#include <iostream>

using namespace std;

// Implement Trie node class
class TrieNode
{
public:
    TrieNode *children[26] = {nullptr};
    bool isEnd;
};

class Solution
{
private:
    TrieNode *root;

public:
    Solution()
    {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word)
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

    // Returns if the word is in the trie.
    bool search(string word)
    {
        TrieNode *node = root;

        for (char ch : word)
        {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                return false;

            node = node->children[idx];
        }
        return node->isEnd;
    }

    // Returns if there is any word in the trie that starts with the given prefix.
    bool startsWith(string prefix)
    {
        TrieNode *node = root;

        for (char ch : prefix)
        {
            int idx = ch - 'a';

            if (node->children[idx] == nullptr)
                return false;

            node = node->children[idx];
        }

        return true;
    }
};

int main()
{
    Solution *trie = new Solution();

    trie->insert("apple");

    std::cout << trie->search("apple") << std::endl;   // 1 (true)
    std::cout << trie->search("app") << std::endl;     // 0 (false)
    std::cout << trie->startsWith("app") << std::endl; // 1 (true)
}