#include <bits/stdc++.h>

// steps
// 1. have a tempStack
// 2. loop over the stack that you want to sort
// 3. while tmpStk.top() > stk.top() pop()
// 4. when tmpStk.Top < stk.top() push in stk
// 5. repeat this process

class Solution
{

public:
  void sort(stack<int> &stk, int top)
  {
    // base case
    if (stk.empty() || stk.top() >= top)
    {
      stk.push(top);
      return;
    }

    // resursive case
    int tmp = stk.top();
    stk.pop();
    sort(stk, top);

    // using recursive backtracking
    stk.push(tmp);
    return;
  }

  stack<int> sortStackII(stack<int> stk)
  {
    if (stk.empty())
      return stk;

    stack<int> tmpStk;

    while (!stk.empty())
    {
      int top = stk.top();
      !tmpStk.empty() ? sort(tmpStk, top) : tmpStk.push(top);

      stk.pop();
    }
    return tmpStk;
  }

  // Time complexity - O(n2)
  // Space complexity - O(2n) = O(n)
  static stack<int> sortStack(stack<int> stk)
  {

    if (stk.empty())
      return stk;

    stack<int> tmpStk;

    while (!stk.empty())
    {
      int top = stk.top();
      stk.pop();

      while (!tmpStk.empty() && top < tmpStk.top())
      {
        stk.push(tmpStk.top());
        tmpStk.pop();
      }

      tmpStk.push(top);
    }
    return tmpStk;
  }
};

int main()
{
  stack<int> stk;

  // stk.push(100);
  // stk.push(22225);
  // stk.push(-222);
  // stk.push(1);
  // stk.push(9);
  // stk.push(9);
  // stk.push(9);
  // stk.push(9);

  stk.push(1);
  stk.push(2);
  stk.push(3);
  stk.push(4);
  stk.push(5);

  // Solution s;

  stack<int> sortedStack = Solution::sortStack(stk);

  while (!sortedStack.empty())
  {
    cout << sortedStack.top() << ", ";
    sortedStack.pop();
  }

  return 0;
}