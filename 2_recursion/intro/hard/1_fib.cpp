#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // Time complexity - O(N)
    // Space complexity - O(N)
    vector<int> fibonacci(int n)
    {
        if (n <= 0)
            return vector<int>(1, 0);

        vector<int> res(n + 1);
        res[0] = 0;
        res[1] = 1;

        if (n == 1)
            return res;

        fibHelper(n, 2, res);

        return res;
    }

    void fibHelper(int n, int start, vector<int> &res)
    {
        if (start > n)
            return;

        int val = res[start - 2] + res[start - 1];
        res[start] = val;
        fibHelper(n, start + 1, res);
    }
};

int main()
{
    Solution sol;
    // Example inputs
    int examples[] = {2, 5, 8, 12};
    int numExamples = sizeof(examples) / sizeof(examples[0]);

    for (int i = 0; i < numExamples; i++)
    {
        printf("Fibonacci Series up to %d : ", examples[i]);

        for (int j = 0; j <= examples[i]; j++)
        {
            vector<int> fib = sol.fibonacci(j);

            for (int x : fib)
                printf("%d ", x);

            printf("\n");
        }
        printf("\n");
    }

    return 0;
}
