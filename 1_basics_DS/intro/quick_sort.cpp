#include <stdio.h>
#include <vector>
using namespace std;

// Quick Sort Steps:
// 1. if arr.size() < 1 return arr
// 2. create a pivot element arr[arr.size()/2]
// 3. create three vector left, middle, right;
// 4. iterate through array and if(x<pivot) left->push, if(x>pivot) right->push, else middle push
// 5. recursice call left and right
// 6. insert middle and right in left
// 7. return left

class Solution
{
public:
  static vector<int> quickSort(vector<int> &arr)
  {
    // Return arr
    if (arr.size() <= 1)
      return arr;

    int pivot = arr[arr.size() / 2];
    vector<int> left, middle, right;

    for (int x : arr)
    {
      if (x < pivot)
        left.push_back(x);
      else if (x > pivot)
        right.push_back(x);
      else
        middle.push_back(x);
    }

    left = quickSort(left);
    right = quickSort(right);
    left.insert(left.end(), middle.begin(), middle.end());
    left.insert(left.end(), right.begin(), right.end());

    return left;
  }
};

int main()
{
  vector<int> arr = {1, 2, 3, 2, 33, 233, 333, 4, 433344, 32, 23232, 22, 11322, 233, 0, 3};
  vector<int> sortedArr = Solution::quickSort(arr);

  for (int x : sortedArr)
    printf("%d ", x);

  printf(".\n");

  return 0;
}