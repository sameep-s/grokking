#include <iostream>

using namespace std;

class Solution
{
public:
    // Time complexity - O(log(min(A,B)))
    // Space complexity - O(log(min(A,B))
    int calculateGCD(int A, int B)
    {
        // Base case
        if (B == 0)
            return A;

        // Recursive case
        return calculateGCD(B, A % B);
    }
};

int main()
{
    Solution s;
    cout << s.calculateGCD(12, 18) << endl;

    return 0;
}