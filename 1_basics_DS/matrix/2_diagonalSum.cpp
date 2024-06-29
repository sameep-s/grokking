#include <iostream>
#include <vector>
using namespace std;

// Time complexity - O(n)
// Space complexity - O(1)

class Solution
{
public:
  static int diagonalSum(vector<vector<int>> &mat)
  {
    int diagonalSum = 0;
    int size = mat.size();

    for (int i = 0; i < size; i++)
    {
      i == size - i - 1 ? diagonalSum += mat[i][i]
                        : diagonalSum += mat[i][size - i - 1] + mat[i][i];
    }

    return diagonalSum;
  }
};

int main()
{
  vector<vector<int>> mat = {{5, 3, 9}, {4, 7, 1}, {8, 6, 2}};
  int diagonalSum = Solution::diagonalSum(mat);

  cout << "diagonalSum :" << diagonalSum << endl;

  return 0;
}