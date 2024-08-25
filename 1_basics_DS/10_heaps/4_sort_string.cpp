#include <iostream>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution
{
public:
    // n = Length of string, m = Number of unique characters
    // Time complexity - O(N+ 2 * mlogm) ~= O(N)
    // Space complexity - O(N+ nLogm) ~= O(N)

    string frequencySort(std::string s)
    {
        string result = "";
        unordered_map<char, int> charFreq;

        for (auto s : s)
            charFreq[s]++; // O(N)

        // compairing function for descending values
        auto comp = [&](char a, char b)
        {
            return charFreq[a] < charFreq[b] || (charFreq[a] == charFreq[b] && a > b);
        };

        priority_queue<char, vector<char>, decltype(comp)> q(comp); // Init max heap

        for (auto [key, _] : charFreq)
            q.push(key); // m*logm times

        while (!q.empty())
        {
            char ch = q.top();
            result += string(charFreq[ch], ch);
            q.pop(); // this takes logm * m times
        }

        return result;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.frequencySort("programming") << std::endl; // Expected: gggrrmmiapo
    std::cout << sol.frequencySort("aab") << std::endl;         // Expected: aab or baa
    std::cout << sol.frequencySort("apple") << std::endl;       // Expected: pplea
}
