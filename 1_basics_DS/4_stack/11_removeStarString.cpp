#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
  // Time complexity = O(n)
  // Space complexity = O(n)

  string removeStars(string s)
  {
    stack<char> stk;
    string res;

    for (auto x : s)
    {
      if (!stk.empty() && x == '*')
      {
        stk.pop();
      }
      else
        stk.push(x);
    }

    while (!stk.empty())
    {
      res = stk.top() + res;

      stk.pop();
    }

    return res;
  }
};

int main()
{
  Solution sol;
  string s = "abc*de*f";

  cout
      << "Solution : " << sol.removeStars(s) << endl;

  return 0;
}