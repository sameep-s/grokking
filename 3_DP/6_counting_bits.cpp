#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
  // Time complexity = O(N)
  // Space complexity = O(N)
  vector<int> countBits(int n)
  {
    vector<int> bits(n + 1);

    for (int i = 1; i <= n; i++)
    {
      int val = i / 2;

      if (i % 2 == 0) // even
        bits[i] = bits[val];
      else // odd
        bits[i] = bits[val] + 1;
    }

    return bits;
  }
};

int main()
{
  Solution sol;
  vector<int> bitsArr = sol.countBits(25);

  return 0;
}
