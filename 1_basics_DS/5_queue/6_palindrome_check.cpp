#include <iostream>
#include <deque>
#include <string>
#include <cctype>

using namespace std;

// class Solution
// {
// public:
//   // Time Complexity - O(2N)- O(N)
//   // Space Complexity - O(N)

//   bool checkPalindrome(string s)
//   {
//     queue<char> q;
//     s.erase(remove(s.begin(), s.end(), ' '), s.end());
//     int len = s.length();

//     for (int i = len - 1; i >= 0; i--)
//     {
//       q.push(tolower(s[i]));
//     }

//     for (char x : s)
//     {
//       if (x != ' ')
//       {
//         cout << x << ", " << q.front() << endl;
//         if (tolower(x) != tolower(q.front()))
//         {
//           return false;
//         }
//       }
//       q.pop();
//     }

//     return true;
//   }
// };

class Solution
{
public:
  // Time complexity - O(N)
  // Space complexity - O(N)

  bool checkPalindrome(const string &s)
  {
    deque<char> dq;

    for (char x : s)
    {
      if (isalnum(x))
      {
        dq.push_back(tolower(x));
      }
    }

    while (dq.size() > 1)
    {
      if (dq.front() != dq.back())
        return false;

      dq.pop_back();
      dq.pop_front();
    }

    return true;
  }
};

int main()
{
  Solution sol;
  std::cout << std::boolalpha;
  std::cout << sol.checkPalindrome("madam") << std::endl;                       // returns: true
  std::cout << sol.checkPalindrome("openai") << std::endl;                      // returns: false
  std::cout << sol.checkPalindrome("A man a plan a canal Panama") << std::endl; // returns: true
  return 0;
}