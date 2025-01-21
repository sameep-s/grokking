#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
  int fibConstant(int n)
  {

    if (n == 0 || n == 1)
      return n;

    int a = 0, b = 1;

    // Bottom up - Dynammic Programming
    for (int i = 2; i <= n; i++)
    {
      int temp = b;

      b = b + a;
      a = temp;
    }

    return b;
  }

  // Time complexity - O(N)
  // Space complexity - O(N)
  int fib(int n)
  {
    vector<int> cache(n + 1, 0);

    cache[0] = 0;
    cache[1] = 1;

    // Bottom up - Dynammic Programming
    for (int i = 2; i <= n; i++)
      cache[i] = cache[i - 1] + cache[i - 2];

    return cache[n];
  }
};

int main()
{
  Solution sol;

  int num = sol.fibConstant(4);
  int num2 = sol.fib(4);

  return 0;
}
