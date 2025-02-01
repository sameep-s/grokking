#include <stdio.h>
#include <vector>

using namespace std;

class Solution
{
public:
  // Time complexity - O(N)
  // Space complexity - O(1)
  // Bottom up dynamic programming
  int minCostClimbing(vector<int> &cost)
  {
    int length = cost.size();
    vector<int> sum(length + 1);

    for (int i = 2; i <= length; i++)
    {
      int cost1 = cost[i - 1] + sum[i - 1];
      int cost2 = cost[i - 2] + sum[i - 2];

      sum[i] = min(cost1, cost2);
    }

    return sum[length];
  }
};

int main()
{
  Solution sol;

  vector<int> vec{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  vector<int> vec2{1, 25, 1};
  vector<int> vec3{10, 15, 20};

  int sol1 = sol.minCostClimbing(vec);
  int sol2 = sol.minCostClimbing(vec2);
  int sol3 = sol.minCostClimbing(vec3);

  printf("vec : %d, vec_2: %d, vec_3: %d. \n", sol1, sol2, sol3);

  return 0;
}