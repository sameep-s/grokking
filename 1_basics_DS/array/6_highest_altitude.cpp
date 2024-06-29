#include <iostream>
#include <vector>

class Solution
{
public:
  static int highestAltitude(std::vector<int> &nums)
  {

    int size = nums.size();
    int maxAlt = 0;
    int currentAlt = 0;

    for (int x : nums)
    {
      currentAlt += x;
      maxAlt = std::max(currentAlt, maxAlt);
    }

    return maxAlt;
  }
};

int main()
{
  std::vector<int> nums = {-5, 1, 5, 0, -7};
  int peak = Solution::highestAltitude(nums);

  std::cout << peak << std::endl;

  return 0;
}