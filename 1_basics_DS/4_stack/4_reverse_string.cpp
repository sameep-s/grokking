#include <iostream>
#include <stack>
using namespace std;

// Time comlexity - O(n)
// Space comlexity - O(n)
class Solution
{

public:
  string getReversedString(string s)
  {
    stack<char> stk;
    string reverseString;

    for (char x : s)
    {
      stk.push(x);
    }

    while (!stk.empty())
    {
      reverseString += stk.top();
      stk.pop();
    }

    return reverseString;
  }
};

int main()
{
  Solution sol;
  string input = "Hello, World!";

  string reverseString = sol.getReversedString(input);

  cout << reverseString << endl;

  return 0;
}