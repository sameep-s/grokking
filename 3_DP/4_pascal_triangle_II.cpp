#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    // using recursion
    vector<int> getRowRecursive(int rowIndex)
    {
        // base case
        if (rowIndex <= 0)
            return {1};

        // Recursive case
        vector<int> prevRow = getRowRecursive(rowIndex - 1);
        vector<int> currRow(rowIndex + 1, 1);

        for (int i = 1; i < rowIndex; i++)
        {
            int val = prevRow[i - 1] + prevRow[i];
            currRow[i] = val;
        }

        return currRow;
    }

    // Using Binomial theorem
    vector<int> getRowBinomial(int rowIdx)
    {
        long r = 1;
        vector<int> rowPcl(rowIdx + 1, 1);

        for (int i = 1; i <= rowIdx + 1; i++)
        {
            r = r * (rowIdx + 1 - i) / i;
            rowPcl[i] = r;
        }

        return rowPcl;
    }

    // using DP
    vector<int> getRow2(int rowIndex)
    {
        vector<int> prevRow;

        for (int i = 0; i <= rowIndex; i++)
        {
            vector<int> currRow(i + 1, 1);

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

        printf(".\n");
    }
};

int main()
{
    Solution sol;

    vector<int> arrRec = sol.getRowRecursive(8);
    vector<int> arrBinomial = sol.getRowBinomial(8);

    return 0;
}