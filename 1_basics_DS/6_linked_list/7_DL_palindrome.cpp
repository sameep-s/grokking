#include <iostream>
using namespace std;

struct DLNode
{
  int val;
  DLNode *next, *prev;

  // Constructor
  DLNode(int x) : val(x), next(nullptr), prev(nullptr){};
};

class Solution
{
public:
  // Time complexity = O(2N) = O(N)
  // Space complexity = O(1)

  bool isPalindrome(DLNode *head)
  {
    if (head == nullptr)
      return true;

    DLNode *curr = head;
    DLNode *end = nullptr;

    while (head != nullptr)
    {
      end = head;
      head = head->next;
    }

    cout << "curr: " << curr->val << ", end " << end->val << endl;
    // This condition handles list with even and odd number fo nodes in the list
    while (curr != end && curr->prev != end)
    {

      if (curr->val != end->val)
        return false;

      curr = curr->next;
      end = end->prev;
    }

    return true;
  }
};

int main()
{
  Solution solution;

  // Test case 1
  DLNode *head1 = new DLNode(1);
  // head1->next = new DLNode(2);
  // head1->next->prev = head1;

  // head1->next->next = new DLNode(1);
  // head1->next->next->prev = head1->next;

  cout << solution.isPalindrome(head1) << endl; // Expected: 1

  return 0;
}