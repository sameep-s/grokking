#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    // Time complexity - O(N)
    // Space complexity - O(N)

    int largestUniqueNumber(vector<int> &A)
    {
        int maxUnique = -1;
        unordered_map<int, int> freq;

        for (int x : A)
        {
            freq[x]++;
        }

        for (auto pair : freq)
        {
            int freqVal = pair.second;

            if (freqVal == 1)
                maxUnique = max(maxUnique, pair.first);
        }

        return maxUnique;
    }
};

int main()
{
    Solution sol;

    vector<int> v1 = {5, 7, 3, 7, 5, 8};
    vector<int> v2 = {1, 2, 3, 2, 1, 4, 4};
    vector<int> v3 = {9, 9, 8, 8, 7, 7};

    cout << sol.largestUniqueNumber(v1) << endl; // Expected: 8
    cout << sol.largestUniqueNumber(v2) << endl; // Expected: 3
    cout << sol.largestUniqueNumber(v3) << endl; // Expected: -1
}