#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    // Time complexity - O(N^2)
    // Space complexity - O(1)

    int lengthOfLongestSubstring(string s)
    {
        // init a set
        unordered_set<char> setChar;

        int maxLength = 0,
            currMaxLen = 0,
            sizeStr = s.size();

        for (int i = 0; i < sizeStr; i++)
        {
            setChar.clear();
            currMaxLen = 0;

            for (int j = i; j < sizeStr; j++)
            {
                int currChar = s[j];

                if (setChar.find(currChar) == setChar.end())
                {
                    currMaxLen++;
                    setChar.insert(currChar);
                }
                else
                    break;
            }

            maxLength = max(maxLength, currMaxLen);
        }

        return maxLength;
    }

    int lengthOfLongestSubstringSlidingWindow(string s)
    {
        // Init unorderedSet
        unordered_set<char> charSet;

        // Init variables
        int maxLength = 0,
            start = 0,
            end = 0,
            n = s.size();

        // Sliding window
        while (end < n)
        {
            if (charSet.find(s[end]) == charSet.end())
            {
                maxLength = max(maxLength, (end - start + 1));
                charSet.insert(s[end]);
                end++;
            }
            else
            {
                charSet.erase(s[start]);
                start++;
            }
        }

        return maxLength;
    }
};

int main()
{
    Solution sol;

    // cout << sol.lengthOfLongestSubstring("abcdaef") << endl;             // Expected: 6
    // cout << sol.lengthOfLongestSubstring("aaaaa") << endl;               // Expected: 1
    // cout << sol.lengthOfLongestSubstring("abrkaabcdefghijjxxx") << endl; // Expected: 10

    cout << sol.lengthOfLongestSubstringSlidingWindow("abcdaef") << endl;             // Expected: 6
    cout << sol.lengthOfLongestSubstringSlidingWindow("aaaaa") << endl;               // Expected: 1
    cout << sol.lengthOfLongestSubstringSlidingWindow("abrkaabcdefghijjxxx") << endl; // Expected: 10

    return 0;
}
