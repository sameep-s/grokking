#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

class Solution
{
public:
    // Time complexity O(N+M)
    // Space complexity O(1)

    int numJewelsInStones(string jewels, string stones)
    {
        // init jewel count
        int jewel_count = 0;

        // create a set for jewels
        unordered_set<char> jewels_set;

        for (char c : jewels)
            jewels_set.insert(c);

        for (char s : stones)
        {
            if (jewels_set.find(s) != jewels_set.end())
                jewel_count++;
        }

        return jewel_count;
    }
};

int main()
{
    Solution sol;

    cout << sol.numJewelsInStones("abc", "aabbcc") << endl; // Expected: 6
    cout << sol.numJewelsInStones("aA", "aAaZz") << endl;   // Expected: 3
    cout << sol.numJewelsInStones("zZ", "zZzZzZ") << endl;  // Expected: 6
}