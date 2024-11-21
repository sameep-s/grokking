#include <stdio.h>
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

class Sol
{
public:
    bool isPrime(int num)
    {
        // Base cases
        if (num == 2)
            return true;

        if (num < 2)
            return false;

        //  Recursive case
        return checkDivisor(num, 2);
    }

    bool checkDivisor(int num, int div)
    {
        // if divisor is greate than sqrt of num, then it is prime
        if (div > sqrt(num))
            return true;

        // if num can be divided by divisor then not
        if (num % div == 0)
            return false;

        return checkDivisor(num, div + 1);
    }
};

int main()
{
    Solution s;
    Sol s2;

    int isPrime = s.isPrime(10);
    int isPrime2 = s2.isPrime(8);

    printf("The prime is: %d \n", isPrime);
    printf("The prime 2 is: %d \n", isPrime2);

    return 0;
}