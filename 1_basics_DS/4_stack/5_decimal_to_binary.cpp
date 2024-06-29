#include <iostream>
#include <stack>
using namespace std;

// Time complexity - O(log(n))
// Space Complexity - O(log(n))

class Solution
{
public:
  void getStack(stack<char> &stk, int num)
  {

    // base case
    if (num <= 1)
    {
      stk.push(char(1));
      return;
    }

    // resursive case
    int remainder = char(num % 2);
    stk.push(remainder);
    getStack(stk, num / 2);
  }

  string decimalToBinary(int num)
  {
    string str;
    stack<char> stk;

    getStack(stk, num);

    while (!stk.empty())
    {
      str += to_string(stk.top());
      stk.pop();
    }

    return str;
  }
};

int main()
{
  Solution s;
  int num = 13;

  cout << "string :" << s.decimalToBinary(num) << endl;

  return 0;
}