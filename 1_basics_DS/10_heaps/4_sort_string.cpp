#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <string>
using namespace std;

class Solution
{
public:
    // n = Length of string, m = Number of unique characters
    // Time complexity - O(N+ 2 * mlogm) ~= O(N)
    // Space complexity - O(N+ mLogm) ~= O(N)

    string frequencySort(std::string s)
    {

        if (s.size() == 0)
            return "";

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

    // Using bucket sort
    string frequencySort_bucket(string s)
    {
        int maxFreq = 0;
        string result;
        unordered_map<char, int> freqMap;

        // create freqMap
        for (auto c : s)
            freqMap[c]++;

        // find maxFreq
        for (auto [_, f] : freqMap)
            maxFreq = max(maxFreq, f);

        // init vector buckets with freq
        vector<vector<char>> buckets(maxFreq + 1);
        for (auto &[c, f] : freqMap)
            buckets[f].push_back(c);

        // build string
        for (int i = maxFreq; i >= 1; i--)
            for (auto c : buckets[i])
                result.append(i, c);

        return result;
    }
};

int main()
{
    Solution sol;
    std::cout << sol.frequencySort("programming") << std::endl; // Expected: gggrrmmiapo
    std::cout << sol.frequencySort("aab") << std::endl;         // Expected: aab or baa
    std::cout << sol.frequencySort("apple") << std::endl;       // Expected: pplea

    // ----------------------------------------------------------- usign bucket sort

    Solution solution;

    string s1 = "trersesess";
    cout << "Output: " << solution.frequencySort_bucket(s1) << endl; // Expected: "sssseeerrt"

    string s2 = "banana";
    cout << "Output: " << solution.frequencySort_bucket(s2) << endl; // Expected: "aaannb"

    string s3 = "abb";
    cout << "Output: " << solution.frequencySort_bucket(s3) << endl; // Expected: "bba
}
