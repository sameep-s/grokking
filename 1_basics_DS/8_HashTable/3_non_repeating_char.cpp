#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // Time complexity -> O(N)+O(N) === O(N)

    // Space complexity(For bound set) - O(1) - This case
    // Space complexity(For unbound set) - O(N)

    int firstUniqChar(string str)
    {
        //   Create a hashmap to store freq of each char
        unordered_map<char, int> freq;
        for (char s : str)
            freq[s]++;

        // Traverse the string inorder and find the first once occuring element
        for (int i = 0; i < str.size(); i++)
        {
            if (freq[str[i]] == 1)
                return i;
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    cout << sol.firstUniqChar("apple") << endl; // Expected: 0
    cout << sol.firstUniqChar("abcab") << endl; // Expected: 2
    cout << sol.firstUniqChar("abab") << endl;  // Expected: -1
}
