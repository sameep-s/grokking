#include <iostream>
#include <queue>
using namespace std;

class Solution
{
  queue<int> queue, aux;

public:
  // Time Complexity push in qeue O(1) pop O(1) loop O(n) swap O(n) = O(2n) = 0(n)
  // Space Complexity -> O(2n) = O(n)

  void push(int x)
  {
    // Implement stack using two queues
    aux.push(x);
    while (!queue.empty())
    {
      aux.push(queue.front());
      queue.pop();
    }
    swap(queue, aux);
  }

  // Time complexity -> O(1)
  // Space complexity -> O(1)

  int pop()
  {
    int top = queue.front();
    queue.pop();
    return top;
  }
};

int main()
{
  Solution s;
  s.push(1);
  s.push(2);
  s.push(3);

  cout << s.pop() << endl; // Should print 3 (last pushed element)
  cout << s.pop() << endl; // Should print 2 (element pushed before 3)

  return 0;
}