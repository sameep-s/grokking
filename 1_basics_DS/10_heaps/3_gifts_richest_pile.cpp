#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution
{
public:
    // Time complexity - O(N)
    // Space complexity - O(N)

    int remainingGifts(std::vector<int> &gifts, int k)
    {
        // Init a priority queue
        priority_queue<int> maxHeap;

        // Insert gifts in maxHeap
        for (auto gift : gifts)
        {
            maxHeap.push(gift);
        }

        // Iterate for k values
        for (int i = 0; i < k; i++)
        {
            int curr = maxHeap.top();
            maxHeap.pop();

            maxHeap.push(sqrt(curr));
        }

        // Result
        int result = 0;
        while (!maxHeap.empty())
        {
            result += maxHeap.top();
            maxHeap.pop();
        }

        return result;
    }
};

int main()
{
    // Create an instance of the Solution class.
    Solution sol;

    // Define test cases.
    std::vector<int> test1 = {4, 9, 16};
    std::vector<int> test2 = {1, 2, 3};
    std::vector<int> test3 = {25, 36, 49};

    // Print results of the method using test cases.
    std::cout << sol.remainingGifts(test1, 2) << std::endl; // Expected: 11
    std::cout << sol.remainingGifts(test2, 1) << std::endl; // Expected: 4
    std::cout << sol.remainingGifts(test3, 3) << std::endl; // Expected: 18

    return 0;
}
