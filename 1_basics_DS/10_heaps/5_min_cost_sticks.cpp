#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int connectSticks(vector<int> &sticks)
    {
        int cost = 0;

        // Init using greater and iterators
        priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(), sticks.end());

        while (minHeap.size() > 1)
        {
            int val1 = minHeap.top();
            minHeap.pop();
            int val2 = minHeap.top();
            minHeap.pop();

            int combined = val1 + val2;
            cost += combined;

            minHeap.push(combined);
        }

        return cost;
    }

    // Time complexity - O(N + N*LogM)
    int connectSticks_MySol(vector<int> &sticks)
    {
        int cost = 0;

        // Labmda function to get Min Heap
        auto comp = [&](int a, int b)
        {
            return a > b;
        };

        // Min heap implementation
        priority_queue<int, vector<int>, decltype(comp)> q(comp);

        for (auto stick : sticks) // 0(N)
            q.push(stick);        // NlogM

        for (int i = q.size(); i > 1; i--) // O(N)
        {
            int t1 = q.top();
            q.pop();
            int t2 = q.top();
            q.pop();

            cost += (t1 + t2);

            q.push(t1 + t2);
        }

        return cost;
    }
};

int main()
{
    Solution sol;

    vector<int> test1 = {1, 2, 3, 4};
    vector<int> test2 = {3, 4, 5};
    vector<int> test3 = {5, 2, 9, 12};

    // cout << sol.connectSticks(test1) << endl; // Expected: 19
    // cout << sol.connectSticks(test2) << endl; // Expected: 19
    // cout << sol.connectSticks(test3) << endl; // Expected: 51

    vector<int> test4 = {1, 1};
    cout << sol.connectSticks_MySol(test4) << endl;
    cout << sol.connectSticks(test4) << endl;

    return 0;
}