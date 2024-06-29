#include <iostream>
#include <vector>
#include <bits/stdc++.h>

class Solution
{
public:
  static vector<int> runnignSum(vector<int> &arr)
  {
    // // base case
    // if (i == arr.size())
    // {
    //   return arr;
    // }

    // // recursive case
    // arr[i] = arr[i] + arr[i - 1];

    // return runnignSum(arr, i + 1);

    //  ------------------ SOL
    vector<int> result(arr.size());

    // check if array is empty
    if (arr.empty())
      return arr;

    // TODO: Write your code here
    int i = 0;
    int n = arr.size();

    while (i < n)
    {
      if (i > 0)
      {
        result[i] = arr[i] + result[i - 1];
        cout << "result :" << result[i] << endl;
      }
      else
        result[i] = arr[i];

      i++;
    }

    return result;
  }
};

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5};
  vector<int> solArr = Solution::runnignSum(arr);

  for (int x : solArr)
  {
    cout << x << ", ";
  }

  return 0;
}
