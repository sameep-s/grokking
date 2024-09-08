#include <bits/stdc++.h>
using namespace std;

// Custom Data type
struct TrieNode
{
    TrieNode *children[26];
    bool isEndOfTheWord;

    TrieNode()
    {
        isEndOfTheWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie
{
public:
    TrieNode *root; // root of the Trie Node

    // Constructor
    Trie()
    {
        root = new TrieNode();
    }

    // Function to insert word into the tree
    // Time complexity - O(N)
    // Space complexity -
    //      Worst case - O(N) - if the word does;nt contain any prefix in the list
    //      Best case - O(1) - If the word is prefix of existing word
    void insert(string word)
    {
        TrieNode *node = root;

        for (char c : word)
        {
            int idx = c - 'a';

            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }

        node->isEndOfTheWord = true;
    }

    // This function is used to search word in a Trie
    //    Time complexity - O(N)
    //    Space complexity - (1) doesn't require space as it is only about traversing
    bool search(string word)
    {
        TrieNode *node = root;

        for (auto c : word)
        {
            int idx = c - 'a';
            if (!node->children[idx])
                return false; // word not found

            node = node->children[idx];
        }

        return node->isEndOfTheWord; // return if the word exists in the Trie
    }

    // This function is used to delete the word from the Trie
    // Time complexity - O(N)
    // Space complexity - O(N) - due to recursion stack begin used
    bool _delete(TrieNode *current, string word, int idx)
    {
        // This line is triggred only if we are at the end of the word
        if (idx == word.size())
        {
            if (current->isEndOfTheWord)
            {
                current->isEndOfTheWord = false;
                return current->children == nullptr;
            }

            return false; // return false if the word is not present in the Trie
        }

        // Check if the word is present in the Trie
        char ch = word[idx];
        TrieNode *node = current->children[ch - 'a'];

        if (!node)
            return false;

        bool shouldDelete = _delete(current, word, idx + 1);

        if (shouldDelete)
        {
            delete current->children[ch - 'a'];
            current->children[ch - 'a'] = nullptr;

            return current->children == nullptr;
        }

        return false;
    }

    void deleteWord(string word)
    {
        _delete(root, word, 0);
    }
};

int main()
{

    return 0;
}