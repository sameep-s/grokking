#include <iostream>
#include <vector>
using namespace std;

// Time compelxity = O(n^2)|| O(m*n)
// Space complexity = O(n)

class Solution
{
public:
  vector<int> findMaxOnesRow(vector<vector<int>> &mat)
  {
    int maxOnesIdx = 0;
    int maxOnesCount = 0;
    // ToDo: Write Your Code Here.
    int sizeOuter = mat.size();

    for (int i = 0; i < sizeOuter; i++)
    {
      int count = 0;
      for (int ele : mat[i])
      {
        if (ele == 1)
          count++;
      }
      if (count > maxOnesCount)
      {
        maxOnesCount = count;
        maxOnesIdx = i;
      }
    }

    return {maxOnesIdx, maxOnesCount};
  }
};

int main()
{
  Solution sol;

  vector<vector<int>> mat = {{1, 0, 1},
                             {0, 0, 1},
                             {1, 1, 0}};

  vector<int> solMat = sol.findMaxOnesRow(mat);

  for (int x : solMat)
  {
    cout << x << ", ";
  }
  cout << endl;

  return 0;
}