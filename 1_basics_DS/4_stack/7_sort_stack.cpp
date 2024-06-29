#include <bits/stdc++.h>

class Solution
{
public:
  stack<int> sortStack(stack<int> &stk)
  {
    stack<int> tempStack;
    // how to sort a stack;

    return stk;
  }
};

int main()
{
  stack<int> stk;

  stk.push(-1);
  stk.push(25);
  stk.push(-2);
  stk.push(31);
  stk.push(99);

  Solution s;

  stack<int> sortedStack = s.sortStack(stk);

  while (!sortedStack.empty())
  {
    cout << sortedStack.top() << ", ";
    sortedStack.pop();
  }

  return 0;
}