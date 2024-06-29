#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution
{

public:
  // Time complexity - O(n)
  // Space complexity - O(n)

  vector<string> generateBinaryNumbers(int n)
  {
    queue<string> q;
    q.push("1");
    vector<string> res;

    while (n--)
    {
      string front = q.front();
      q.pop();

      string s1 = front;
      res.push_back(front);

      string s2 = s1;

      q.push(s1.append("0"));
      q.push(s2.append("1"));
    }

    return res;
  }
};

// Main function
int main()
{
  Solution sol;
  vector<string> binaryNums = sol.generateBinaryNumbers(5); // Generate 5 binary numbers.

  for (string binaryNum : binaryNums)
  {
    cout << binaryNum << endl; // Print each generated binary number.
  }
  return 0;
}