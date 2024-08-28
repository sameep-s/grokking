#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

public:
    // Time complexity - O(LogN)
    // Space complexity - O(N)
    virtual void insertNum(int num)
    {
        // Push numbers
        if (max_heap.empty() || max_heap.top() >= num)
            max_heap.push(num);
        else
            min_heap.push(num);

        // Balance heaps
        if (max_heap.size() > min_heap.size() + 1)
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if (min_heap.size() > max_heap.size())
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    // Time complexity - O(1)
    virtual double findMedian()
    {
        if ((min_heap.size() + max_heap.size()) % 2 == 0)
            return min_heap.top() / 2.0 + max_heap.top() / 2.0;

        return max_heap.top();
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    sol.insertNum(3);
    sol.insertNum(1);
    cout << "The median is: " << sol.findMedian() << endl;

    sol.insertNum(5);
    cout << "The median is: " << sol.findMedian() << endl;

    sol.insertNum(4);
    cout << "The median is: " << sol.findMedian() << endl;
}
