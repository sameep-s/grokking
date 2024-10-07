#include <iostream>
using namespace std;

class Solution
{

public:
    // Time complexity - O(N)
    // Space complexity - O(N)
    int calculateSum(int num)
    {
        //   Base case
        if (num == 0)
            return 0;

        //   Recursive case
        int sum = num + calculateSum(num - 1);

        return sum;
    }
};

int main()
{
    Solution s;
    cout << s.calculateSum(10) << endl;

    return 0;
}