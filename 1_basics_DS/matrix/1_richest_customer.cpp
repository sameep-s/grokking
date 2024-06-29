#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  static int calcMaxWealth(vector<vector<int>> &accounts)
  {
    int maxWealth = 0;

    for (vector<int> account : accounts)
    {
      int innerSum = 0;

      for (int x : account)
      {
        innerSum += x;
      }

      if (innerSum > maxWealth)
        maxWealth = innerSum;
    }

    return maxWealth;
  }
};

int main()
{
  vector<vector<int>> accounts = {{1, 2, 3}, {2, 3, 4}};
  cout << Solution::calcMaxWealth(accounts);

  return 0;
}