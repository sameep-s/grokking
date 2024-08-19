#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    // Time complexity - O(2N)
    // Space complexity - O(N)

    bool uniqueOccurrences(vector<int> &arr)
    {
        // init a hashMap
        unordered_map<int, int> freq;
        // init a set
        unordered_set<int> int_set;

        // populate the hashMap
        for (int i : arr)
            freq[i]++;

        for (auto [_, f] : freq)
        {
            if (int_set.find(f) != int_set.end())
                return false;

            int_set.insert(f);
        }

        return true;
    }
};

int main()
{
    Solution sol;

    std::vector<int> arr1 = {4, 5, 4, 6, 6, 6};
    std::vector<int> arr2 = {7, 8, 8, 9, 9, 9, 10, 10};
    std::vector<int> arr3 = {11, 12, 13, 14, 14, 15, 15, 15};

    std::cout << sol.uniqueOccurrences(arr1) << std::endl;
    std::cout << sol.uniqueOccurrences(arr2) << std::endl;
    std::cout << sol.uniqueOccurrences(arr3) << std::endl;
}
