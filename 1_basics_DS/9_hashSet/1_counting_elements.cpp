#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    // Time complexity - O(N)
    // Space complexity - O(N)
    int countElements(vector<int> &arr)
    {
        // init an unordered set
        unordered_set<int> num_set(arr.begin(), arr.end());
        int count = 0;

        for (int x : arr)
        {
            if (num_set.find(x + 1) != num_set.end())
                count++;
        }

        // return count
        return count;
    }
};

int main()
{
    Solution sol;

    vector<int> v1 = {4, 3, 1, 5, 6};
    vector<int> v2 = {7, 8, 9, 10};
    vector<int> v3 = {11, 13, 15, 16};

    cout << sol.countElements(v1) << endl; // Expected: 3
    cout << sol.countElements(v2) << endl; // Expected: 3
    cout << sol.countElements(v3) << endl; // Expected: 1
}
