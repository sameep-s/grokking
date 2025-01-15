#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    // using recursion
    vector<int> getRow(int rowIndex)
    {
        // base case

        vector<int> prevRow = getRow(rowIndex - 1);

        return prevRow;
    }

    // using DP
    vector<int> getRow2(int rowIndex)
    {
        vector<int> prevRow;

        for (int i = 1; i < rowIndex; i++)
        {
            vector<int> currRow = vector(rowIndex, 1);

            for (int j = 1; j < i; j++)
                currRow[j] = prevRow[j - 1] + prevRow[j];

            prevRow = currRow;
        }

        return prevRow;
    }

    // Print Triangle
    void printTriangle(vector<int> arr)
    {
        for (auto val : arr)
            printf("%d ", val);

        printf("\n");
    }
};

int main()
{
    Solution sol;

    vector<int> arr = sol.getRow2(4);
    sol.printTriangle(arr);

    return 0;
}