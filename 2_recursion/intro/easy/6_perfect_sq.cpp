#include <stdio.h>
using namespace std;

class Solution
{
public:
    // Time complexity - O(Log(N)) binary search
    // Space complexity - O(Log(N)) binary search
    bool isPerfectSqHelper(int num, int l, int r)
    {
        // Base case
        if (l > r)
            return false;

        int mid = (l + r) / 2;
        long long midSq = mid * mid;

        // Recursive case
        if (midSq == num)
            return true;
        else if (midSq > num)
            return isPerfectSqHelper(num, l, mid - 1);
        else
            return isPerfectSqHelper(num, mid + 1, r);
    }

    // Can we use binary search for perfect square
    bool isPerfectSquare(int num)
    {
        return isPerfectSqHelper(num, 0, num);
    }
};

int main()
{
    Solution s;
    bool isPerfectSq = s.isPerfectSquare(121);

    printf("The perfect square is: %d \n", isPerfectSq);

    return 0;
}
