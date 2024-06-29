#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode *next) : val(val), next(next) {}
};

class Solution
{
public:
  //  Time complexity = O(N)
  //  Space complexity = O(1)

  ListNode *swapPairs(ListNode *head)
  {
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *prev = &dummy;

    while (head && head->next)
    {
      ListNode *first = head;
      ListNode *second = head->next;

      first->next = second->next;
      second->next = first;
      prev->next = second;

      head = first->next;
      prev = first;
    }

    return dummy.next;
  }
};

int main()
{
  Solution solution;

  // Initialize the list and perform the swap.
  ListNode *head1 = new ListNode(1);
  head1->next = new ListNode(2);
  head1->next->next = new ListNode(3);
  head1->next->next->next = new ListNode(4);

  ListNode *newHead1 = solution.swapPairs(head1);
  // Print the list after swapping pairs.
  while (newHead1)
  {
    std::cout << newHead1->val << " ";
    newHead1 = newHead1->next;
  }
  std::cout << std::endl;

  // Initialize another list and perform the swap.
  ListNode *head2 = new ListNode(1);
  head2->next = new ListNode(2);
  head2->next->next = new ListNode(2);
  head2->next->next->next = new ListNode(3);

  ListNode *newHead2 = solution.swapPairs(head2);
  // Print the list after swapping pairs.
  while (newHead2)
  {
    std::cout << newHead2->val << " ";
    newHead2 = newHead2->next;
  }
  std::cout << std::endl;

  // Initialize another list and perform the swap.
  ListNode *head3 = new ListNode(3);
  head3->next = new ListNode(3);
  head3->next->next = new ListNode(3);

  ListNode *newHead3 = solution.swapPairs(head3);
  // Print the list after swapping pairs.
  while (newHead3)
  {
    std::cout << newHead3->val << " ";
    newHead3 = newHead3->next;
  }
  std::cout << std::endl;

  return 0;
}
