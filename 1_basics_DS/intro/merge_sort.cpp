#include <iostream>
#include <vector>
using namespace std;

// MERGE SORT STEPS

// 1. find mid point and make two arrays left and right, do this recursively till min elements are left
// 2. start compairing if arr[l] < arr[r] push left[i] and i++ else push right[j] and j++ and k++
// 3. condition 1 if i and j and both less than size of left and right
// 4. condition 2 if i > left.size() then push all elements in left in arr
// 5. condition 3 if j > right.size() then push all elements in right in arr
// 6. these are all the steps in merge sort.

class Solution
{
public:
  static void mergeSort(vector<int> &arr)
  {
    if (arr.size() > 1)
    {
      int mid = arr.size() / 2;

      vector<int> left(arr.begin(), arr.begin() + mid);
      vector<int> right(arr.begin() + mid, arr.end());

      mergeSort(left);
      mergeSort(right);

      int i = 0, j = 0, k = 0;

      // condition 1
      while (i < left.size() && j < right.size())
      {
        if (left[i] < right[j])
        {
          arr[k++] = left[i++];
        }
        else
        {
          arr[k++] = right[j++];
        }
      }

      // condition 2
      while (i < left.size())
      {
        arr[k++] = left[i++];
      }

      // condition 3
      while (j < right.size())
      {
        arr[k++] = right[j++];
      }
    }
  }
};

int main()
{
  vector<int> arr = {12, 11, 13, 5, 6, 200, 0, 321, 0, 333, 99392, 110212, 7};

  // calling mergeSort method
  Solution::mergeSort(arr);
  for (int val : arr)
  {
    cout << val << ", ";
  }

  return 0;
}