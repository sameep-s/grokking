#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
  // Time complexity = O(n)
  // Space complexity = O(n)

  string makeGood(string s)
  {

    stack<char> stk;
    string res;

    for (char c : s)
    {
      if (!stk.empty() && stk.top() != c && tolower(stk.top()) == tolower(c))
      {
        stk.pop();
      }
      else
        stk.push(c);
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
  string s = "AaBbCcDdEeff";
  Solution sol;

  cout << "Soll :" << sol.makeGood(s) << endl;

  return 0;
}