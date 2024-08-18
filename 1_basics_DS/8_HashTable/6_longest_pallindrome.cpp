#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    // Time complexity - O(1)
    // Space complexity - O(1)
    int longestPalindrome(string s)
    {
        // Init max len
        int maxLen = 0;
        int isOdd = false;

        // init a hashmap to store the char freq
        unordered_map<char, int> charMap;

        // Populate the charMap
        for (char c : s)
        {
            charMap[c]++;
        }

        for (auto pair : charMap)
        {
            cout << "Pair: " << pair.first << ", " << pair.second << endl;
            if (pair.second % 2 == 0)
                maxLen += pair.second;
            else
            {
                maxLen += (pair.second - 1);
                isOdd = true;
            }
        }

        if (isOdd)
            maxLen++;

        return maxLen;
    }
};

int main()
{
    Solution sol;
    cout << sol.longestPalindrome("bananas") << endl;  // Expected output: 5
    cout << sol.longestPalindrome("applepie") << endl; // Expected output: 7
    cout << sol.longestPalindrome("racecar") << endl;  // Expected output: 7
    return 0;
}