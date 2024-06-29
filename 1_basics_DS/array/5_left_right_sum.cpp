#include <iostream>
#include <vector>
#include <cmath>

class Solution
{
public:
  static std::vector<int> leftRightSum(std::vector<int> &nums)
  {
    int size = nums.size();
    std::vector<int> leftSum(size), rightSum(size), diffArr(size);

    // left sum
    leftSum[0] = nums[0];
    for (int i = 1; i < size; i++)
    {
      leftSum[i] = nums[i] + leftSum[i - 1];
    }

    // right sum
    rightSum[size - 1] = nums[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
      rightSum[i] = nums[i] + rightSum[i + 1];
    }

    // diffArr
    for (int i = 0; i < size; i++)
    {
      diffArr[i] = abs(leftSum[i] - rightSum[i]);
    }

    return diffArr;
  }
};

int main()
{
  std::vector<int> arr = {1, 2, 3, 4};

  std::vector<int> diffArr = Solution::leftRightSum(arr);

  for (int x : diffArr)
  {
    std::cout << x << " ";
  }

  return 0;
}