#include <iostream>
#include <string>

using namespace std;

class TrieNode
{
public:
    TrieNode *children[26] = {nullptr};
    bool isEnd = false;
};

class Trie
{
private:
    TrieNode *root;

    bool searchInNode(const string word, TrieNode *node)
    {
        for (int i = 0; i < word.size(); i++)
        {
            char ch = word[i];

            if (ch == '.')
            {
                for (int j = 0; j < 26; ++j)
                    if (node->children[j] && searchInNode(word.substr(i + 1), node->children[j]))
                        return true;

                return false;
            }
            else
            {
                if (node->children[ch - 'a'] == nullptr)
                    return false;

                node = node->children[ch - 'a'];
            }
        }

        return node->isEnd;
    }

public:
    Trie() : root(new TrieNode) {};

    void insert(const string word)
    {

        TrieNode *node = root;

        for (auto ch : word)
        {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }

        node->isEnd = true;
    }

    bool search(const string string)
    {
        return searchInNode(string, root);
    }
};

class Solution
{
private:
    Trie *root;

public:
    Solution()
    {
        root = new Trie();
    }

    void addWord(const std::string &word)
    {
        root->insert(word);
    }

    bool search(const std::string &word)
    {
        return root->search(word);
    }
};

int main()
{
    Solution obj;

    obj.addWord("apple");
    obj.addWord("banana");

    std::cout << obj.search("apple") << std::endl; // 1 (true)
    std::cout << obj.search("a.ple") << std::endl; // 1 (true)
    std::cout << obj.search(".....") << std::endl; // 1 (true)

    cout << "p-a :" << 'p' - 'a' << endl;
}
