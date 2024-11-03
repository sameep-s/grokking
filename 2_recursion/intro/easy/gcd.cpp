#include <iostream>

using namespace std;

class Solution
{
public:
    // Time complexity - O(log(min(A,B)))
    // Space complexity - O(log(min(A,B))
    // In this case we utilize Eucledean theorem that if we replace the larger number with the remainder of it's
    // division with smaller number the GCD remains the samne
    int calculateGCD(int A, int B)
    {
        //  Base case
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
    cout << s.calculateGCD(100, 120) << endl;

    return 0;
}