#include <iostream>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  // Time complexity - O(m+n)
  // Space complexity - O(1)

  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode dummy(-1);
    ListNode *curr = &dummy;

    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        curr->next = l1;
        l1 = l1->next;
      }
      else
      {
        curr->next = l2;
        l2 = l2->next;
      }

      curr = curr->next;
    }

    // Points the remaining list to curr
    curr->next = l1 ? l1 : l2;

    return dummy.next;
  }
};

int main()
{
  Solution solution;

  // Create the first example ListNode instances
  ListNode *head1 = new ListNode(1);
  head1->next = new ListNode(1);
  head1->next->next = new ListNode(2);

  // Create the second example ListNode instances
  ListNode *head2 = new ListNode(1);
  head2->next = new ListNode(2);
  head2->next->next = new ListNode(2);
  head2->next->next->next = new ListNode(3);

  // Create the third example ListNode instances
  ListNode *head3 = new ListNode(3);
  head3->next = new ListNode(3);
  head3->next->next = new ListNode(3);

  // Call mergeTwoLists method and print the result
  ListNode *result1 = solution.mergeTwoLists(head1, head2);
  while (result1)
  {
    std::cout << result1->val << " ";
    result1 = result1->next;
  }
  std::cout << std::endl;

  ListNode *result2 = solution.mergeTwoLists(head2, head3);
  while (result2)
  {
    std::cout << result2->val << " ";
    result2 = result2->next;
  }
  std::cout << std::endl;

  return 0;
}
