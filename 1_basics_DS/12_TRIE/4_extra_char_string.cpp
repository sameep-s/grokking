#include <iostream>
#include <vector>
#include <string>
#include <memory>

using namespace std;
// To be done after dyncmic programming section

class TrieNode
{
public:
    vector<TrieNode *> children; // Changed to vector of TrieNode pointers
    bool isEnd;

    TrieNode() : children(26, nullptr), isEnd(false) {}
};

class Solution
{
private:
    TrieNode *root = new TrieNode();
    void buildTrie(string s)
    {
        TrieNode *node = root;

        for (char ch : s)
        {
            int idx = ch - 'a';
            if (node->children[idx] == nullptr)
                node->children[idx] = new TrieNode;

            node = node->children[idx];
        }
    }

public:
    int minExtraChar(string s, vector<string> &dictionary) {}
};

int main()
{
    Solution solution;
    vector<string> dictionary1 = {"race", "car"};
    cout << solution.minExtraChar("amazingracecar", dictionary1) << endl; // Output: 7

    vector<string> dictionary2 = {"keep", "read"};
    cout << solution.minExtraChar("bookkeeperreading", dictionary2) << endl; // Output: 9

    vector<string> dictionary3 = {"dog", "bark", "night"};
    cout << solution.minExtraChar("thedogbarksatnight", dictionary3) << endl; // Output: 6

    return 0;
}
