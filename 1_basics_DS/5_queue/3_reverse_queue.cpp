#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution
{
public:
  // Time complexity = O(2n)= O(n)
  // Space complexity = O(n)

  static queue<int> reverseQueue(queue<int> q)
  {
    stack<int> stk;

    while (!q.empty())
    {
      int ele = q.front();
      q.pop();
      stk.push(ele);
    }

    while (!stk.empty())
    {
      int data = stk.top();
      q.push(data);
      stk.pop();
    }

    return q;
  }
};

int main()
{

  // Create a queue and add some elements to it.
  queue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);

  Solution sol;

  // Call the function to reverse the order of elements in the queue.
  q = sol.reverseQueue(q);

  // Print each element of the now-reversed queue and remove them.
  while (!q.empty())
  {
    cout << q.front() << " ";
    q.pop();
  }

  cout << endl;

  return 0;
}