#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    // Time complexity - O(N+M) -> N=size(ransomNote), M=size(magazine)
    // Space complexity - O(1) -> constant time

    bool canConstruct(string ransomNote, string magazine)
    {
        cout << "------------------------------------------------------------------------" << endl;

        // Init a ransomNote Freq hashMap
        unordered_map<char, int> charCount;

        // Populate hashMap
        for (char c : magazine)
        {
            charCount[c]++;
        }

        // Traverse magazine string
        for (char c : ransomNote)
        {
            cout << "charCount :" << charCount[c] << endl;
            if (charCount[c] == 0)
                return false;
            charCount[c]--;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    cout << sol.canConstruct("hello", "hellworld") << endl; // Expected: true
    cout << sol.canConstruct("notes", "stoned") << endl;    // Expected: true
    cout << sol.canConstruct("apple", "pale") << endl;      // Expected: false
}
