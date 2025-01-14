#include <stdio.h>
using namespace std;

int climbStaris(int lvl)
{
    int prev1 = 1;
    int prev2 = 1;

    for (int i = 2; i <= lvl; i++)
    {
        int curr = prev1 + prev2;

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int climb2 = climbStaris(4);
    printf("The number of ways we can climb 4 stairs: %d\n", climb2);

    return 0;
}
