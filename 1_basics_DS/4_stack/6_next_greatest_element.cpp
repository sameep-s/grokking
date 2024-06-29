#include <bits/stdc++.h>

// init an arr res of arr.size()
// iterate from right to left
// if arr[i] < stk.top() stk.top() -> next greatest -> stk.push()
// if arr[i] > stk.top() -> stk.pop() till stk.empty(), then stk.push()
// stk.top() in res array or if we don't find it's -1 and then stk.push(arr[i])
// stack will keep elements in reverse order

// time complexity = O(n) as every element is pushed in stack exactly once
// space complexity = O(n)

class Solution
{
public:
  vector<int> nextLargestElement(vector<int> arr)
  {

    int size = arr.size();

    vector<int> res(size, -1);
    stack<int> stk;

    for (int i = size - 1; i >= 0; i--)
    {

      // stack in not empty but stk.top() < arr[i]
      while (!stk.empty() && stk.top() < arr[i])
      {
        stk.pop();
      }

      //
      if (!stk.empty() && stk.top() > arr[i])
      {
        res[i] = stk.top();
      }

      stk.push(arr[i]);
    }

    return res;
  }
};

int main()
{

  vector<int> arr = {4, 5, 2, 25};
  Solution s;

  vector<int> res = s.nextLargestElement(arr);

  for (int x : res)
  {
    cout << x << ", ";
  }

  return 0;
}