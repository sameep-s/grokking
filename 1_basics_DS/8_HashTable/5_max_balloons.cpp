#include <iostream>
#include <unordered_map>
#include <string>
#include <limits.h>

using namespace std;

class Solution
{
public:
    // Time complexity - O(N)
    // Space complexity - O(1)

    int maxNumberOfBalloons(string text)
    {

        int minCount = INT_MAX;

        // Declare char_count hashMap
        unordered_map<char, int> charCount;

        // Store all the strins in a hashmap
        for (char c : text)
        {
            charCount[c]++;
        }

        // Count the max number of balloons
        minCount = min(minCount, charCount['b']);
        minCount = min(minCount, charCount['a']);
        minCount = min(minCount, charCount['l'] / 2);
        minCount = min(minCount, charCount['o'] / 2);
        minCount = min(minCount, charCount['n']);

        return minCount;
    }
};

int main()
{
    Solution sol;
    cout << sol.maxNumberOfBalloons("balloonballoon") << endl;   // Expected: 2
    cout << sol.maxNumberOfBalloons("bbaall") << endl;           // Expected: 0
    cout << sol.maxNumberOfBalloons("balloonballoooon") << endl; // Expected: 2
}
