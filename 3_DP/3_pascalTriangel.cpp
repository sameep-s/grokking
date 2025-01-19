#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateRecursion(int numRows)
    {
        if (numRows == 1)
            return {{1}};

        vector<vector<int>> prevRows = generateRecursion(numRows - 1);
        vector<int> newRow = vector(numRows, 1);

        for (int i = 1; i < numRows - 1; i++)
            newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];

        prevRows.push_back(newRow);

        return prevRows;
    }

    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> pascalArr(numRows);
        vector<int> prevRow;

        for (int i = 0; i < numRows; i++)
        {
            vector<int> currRow(i + 1, 1);

            // It won't work for values of i = 0 and 1;
            for (int j = 1; j < i; j++)
                currRow[j] = prevRow[j - 1] + prevRow[j];

            pascalArr[i] = currRow;
            prevRow = currRow;
        }

        return pascalArr;
    }

    void printTriangle(vector<vector<int>> arr)
    {
        printf("\n");

        for (vector<int> subArr : arr)
        {
            for (int val : subArr)
                printf("%d, ", val);

            printf("\n");
        }
    }
};

int main()
{

    Solution sol;
    vector<vector<int>> arr = sol.generateRecursion(5);

    sol.printTriangle(arr);

    return 0;
}
