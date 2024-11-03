#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    // Time complexity - O(sqrt(N))
    // Space complexity - O(sqrt(N))
    bool isPrime(int num)
    {
        // Base case
        if (num < 2)
            return false;

        if (num == 2)
            return true;

        // Recrusive case
        return checkDivisor(num, 2);
    }

    bool checkDivisor(int num, int divisor)
    {
        // Base case
        if (divisor > sqrt(num))
            return true;

        if (num % divisor == 0)
            return false;

        // Recursive case
        return checkDivisor(num, divisor + 1);
    }
};

int main()
{
    Solution s;

    return 0;
}