#include <bits/stdc++.h>

class Solution
{
public:
  // Time complexity = O(N)
  // Space complexity = O(K)

  vector<int> printMax(vector<int> arr, int k)
  {
    vector<int> res;
    int size = arr.size();
    deque<int> dq(k);

    int i;
    for (i = 0; i < k; i++)
    {
      while (!dq.empty() && arr[i] >= arr[dq.back()])
        dq.pop_back();

      dq.push_back(i);
    }

    for (; i < size; i++)
    {
      res.push_back(arr[dq.front()]);

      // Remove elements that are no longer in the current window
      while (!dq.empty() && dq.front() <= i)
        dq.pop_front();

      // Remove elements that are smaller than the current element from the back of the dedque
      while (!dq.empty() && arr[i] >= arr[dq.back()])
        dq.pop_back();

      dq.push_back(i);
    }

    res.push_back(arr[dq.front()]);
    return res;
  }
};

int main()
{
  // 0,1,2,3,4,5,6
  int arr[] = {12, 1, 78, 90, 57, 89, 56}; //
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 2;

  Solution sol;
  vector<int> result = sol.printMax(vector<int>(arr, arr + n), k);

  // Print the result
  for (int i = 0; i < result.size(); i++)
  {
    cout << result[i] << ", ";
  }
  cout << endl;

  return 0;
}