#include <bits/stdc++.h>

class Solution
{
public:
  static bool containsDuplicate(vector<int> arr)
  {
    int size = arr.size();
    unordered_set<int> set;

    for (int x : arr)
    {
      if (set.count(x))
        return true;

      set.insert(x);
    }
    return false;
  }
};

int main()
{
  vector<int> arr = {1, 2, 3, 4, 5, 6};

  cout << Solution::containsDuplicate(arr) << endl;

  return 0;
}