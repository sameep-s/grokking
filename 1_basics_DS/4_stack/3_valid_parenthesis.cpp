#include <iostream>
#include <stack>
using namespace std;

// Time complexity - O(n)
// space complexity - O(n)

class Solution
{

public:
  bool isValid(string s)
  {
    // length of the string
    int len = s.length();

    // define stack
    stack<char> stk;

    // if length of string is odd
    if (len % 2 != 0)
      return false;

    for (char x : s)
    {
      if (x == '{' || x == '(' || x == '[')
      {
        stk.push(x);
      }
      else
      {
        char top = stk.top();
        stk.pop();

        if (x == '}' and top != '{')
          return false;
        if (x == ')' and top != '(')
          return false;
        if (x == ']' and top != '[')
          return false;
      }
    }

    return true;
  }
};

int main()
{
  string s = "{[(}]}";
  Solution sol;

  bool isStringValid = sol.isValid(s);

  cout << isStringValid << endl;

  return 0;
}