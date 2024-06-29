#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;

  // Constructor
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  // Time complexity = O(1)
  // Space complexity = O(1)

  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *curr = head;

    while (curr && curr->next)
    {
      ListNode *next = curr->next;

      if (curr->val == next->val)
        curr->next = next->next;
      else
        curr = next;
    }

    return head;
  }

  void printList(ListNode *head)
  {
    ListNode *curr = head;

    while (curr != nullptr)
    {
      cout << curr->val << ", ";
      curr = curr->next;
    }

    cout << endl;
  }
};

int main()
{
  Solution solution;

  // Test Example 1
  ListNode *head1 = new ListNode(1);
  head1->next = new ListNode(1);
  head1->next->next = new ListNode(2);
  ListNode *result1 = solution.deleteDuplicates(head1); // Expected: 1 -> 2
  solution.printList(result1);

  // Test Example 2
  ListNode *head2 = new ListNode(1);
  head2->next = new ListNode(2);
  head2->next->next = new ListNode(2);
  head2->next->next->next = new ListNode(3);
  ListNode *result2 = solution.deleteDuplicates(head2); // Expected: 1 -> 2 -> 3
  solution.printList(result2);

  // Test Example 3
  ListNode *head3 = new ListNode(3);
  head3->next = new ListNode(3);
  head3->next->next = new ListNode(3);
  ListNode *result3 = solution.deleteDuplicates(head3); // Expected: 3
  solution.printList(result3);

  return 0;
}
