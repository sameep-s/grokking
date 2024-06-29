#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
  // Time Complexity - O(2n) -> O(n)
  // Space Complexity - O(n)

  string simplifyPath(string s)
  {
    int lenStr = s.length();
    if (lenStr == 0)
      return s;

    string str = "";
    stack<string> stk;
    istringstream stream(s);
    string p;

    while (getline(stream, p, '/'))
    {
      if (p == "..")
      {
        if (!stk.empty())
          stk.pop();
      }

      else if (!p.empty() && p != ".")
      {
        stk.push(p);
      }
    }

    while (!stk.empty())
    {
      str = "/" + stk.top() + str;
      stk.pop();
    }

    return str.empty() ? "/" : str;
  }
};

int main()
{
  string s = "/a//b////c/d//././/..";
  string s2 = "/../";
  Solution sol;

  cout << "str= " << endl
       << sol.simplifyPath(s) << endl;

  return 0;
}