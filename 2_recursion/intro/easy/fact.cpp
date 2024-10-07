#include <iostream>

using namespace std;

class Solution
{
public:
    // Time complexity - O(N)
    // Space complexity - O(N)
    int calculateFactorial(int num)
    {
        // Base case
        if (num == 0)
            return 1;

        // Recursive case
        int fact = num * calculateFactorial(num - 1);

        return fact;
    }
};

int main()
{

    Solution s;

    cout << s.calculateFactorial(5) << endl;

    return 0;
}