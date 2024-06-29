#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

class Solution
{
public:
  // Time complexity = O(2n) = O(n)
  // Space complexity = O(n)

  static string removeDuplicates(string s)
  {
    string result = "";
    stack<char> stk;

    for (auto x : s)
    {
      cout << "x :" << x << endl;

      if (!stk.empty() && stk.top() == x)
      {
        stk.pop();
      }
      else
        stk.push(x);
    }

    while (!stk.empty())
    {
      result = stk.top() + result;
      stk.pop();
    }

    return result;
  }
};

int main()
{
  string s = "abbaca";

  cout << "Solution" << Solution::removeDuplicates(s) << endl;

  return 0;
}