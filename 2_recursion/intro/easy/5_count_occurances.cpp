#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Time complexity = O(N)
    // Space complexity = O(N)
    int countOccurrences(const vector<int> &arr, int key)
    {
        int count = 0;
        countOccurancesHelper(arr, key, 0, count);

        return count;
    }

    int countOccr(const vector<int> arr, int key)
    {
        return countOccurancesHelper2(arr, key, 0);
    }

    void countOccurancesHelper(const vector<int> &arr, int key, int idx, int &count)
    {
        // Recursive case
        if (arr[idx] == key)
            count++;

        // Base case
        if (arr.size() - 1 == idx)
            return;

        countOccurancesHelper(arr, key, idx + 1, count);
    }

    int countOccurancesHelper2(const vector<int> arr, int key, int idx)
    {
        if (idx >= arr.size())
            return 0;

        int count = arr[idx] == key ? 1 : 0;

        return count + countOccurancesHelper2(arr, key, idx + 1);
    }
};

int main()
{
    vector<int> arr = {23, 32, 3, 3, 3, 4, 4, 3, 2, 4, 2};
    Solution s;

    int count = s.countOccurrences(arr, 2);
    int count2 = s.countOccr(arr, 2);

    printf("The number of countOccurrences:%d and countOccr:%d.\n", count, count2);
}