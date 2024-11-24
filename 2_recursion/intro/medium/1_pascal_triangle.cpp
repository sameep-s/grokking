#include <bits/stdc++.h>

// Class solution
class Solution
{
public:
    //   Time complexity - logO(N^2)
    //   Space complexity - logO(N^2)
    vector<vector<int>> generatePascalTriangle(int numRows)
    {
        vector<vector<int>> pt(numRows);

        // Initialize each row with proper size
        for (int i = 0; i < numRows; i++)
            pt[i].resize(i + 1); // Each row i has i+1 elements

        for (int i = 0; i < numRows; i++)
            for (int j = 0; j <= i; j++)
            {
                int num = generatePascalTriangleHelper(i, j, pt);
                pt[i][j] = num;
            }

        return pt;
    }

    int generatePascalTriangleHelper(int i, int j, vector<vector<int>> &pt)
    {
        // Base case
        if (j == 0 || j == i || i == 1)
            return 1;

        // Recursive case
        return pt[i - 1][j] + pt[i - 1][j - 1];
    }
};

void printPascalTriangle(vector<vector<int>> pt)
{
    for (vector<int> arr : pt)
    {
        for (auto x : arr)
            printf("%d, ", x);

        printf("\n");
    }
}

int main()
{
    Solution s;
    vector<vector<int>> pt = s.generatePascalTriangle(12);

    printPascalTriangle(pt);

    return 0;
}