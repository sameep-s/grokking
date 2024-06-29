#include <iostream>
#include <queue>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
  queue<pair<vector<int>::iterator, vector<int>::iterator>> q;

public:
  Solution(vector<int> &v1, vector<int> &v2)
  {
    if (!v1.empty())
    {
      q.push(make_pair(v1.begin(), v1.end()));
    }

    if (!v2.empty())
    {
      q.push(make_pair(v2.begin(), v2.end()));
    }
  }

  // Time complexity - O(1)
  // Space complexity - O(m) m= number of queues
  int next()
  {
    vector<int>::iterator front = q.front().first;
    vector<int>::iterator end = q.front().second;
    q.pop();

    if (front + 1 != end)
    {
      q.push(make_pair(front + 1, end));
    }
    return *front;
  }

  // Time complexity - O(1)
  // Space complexity - O(1)
  bool hasNext()
  {
    return !q.empty();
  }
};

int main()
{
  vector<int> v1 = {1, 2};
  vector<int> v2 = {3, 4, 5, 6};
  Solution i(v1, v2);
  cout << i.next() << endl;                 // returns 1
  cout << i.next() << endl;                 // returns 3
  cout << i.next() << endl;                 // returns 2
  cout << i.next() << endl;                 // returns 4
  cout << i.next() << endl;                 // returns 5
  cout << i.next() << endl;                 // returns 6
  cout << boolalpha << i.hasNext() << endl; // returns false
  return 0;
}