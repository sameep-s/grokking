#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  // Time complexity = O(N)
  // Space complexity = O(1)

  ListNode *reverseList(ListNode *head)
  {

    ListNode *curr = head;
    ListNode *prev = nullptr;

    while (curr != nullptr)
    {
      ListNode *next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
    }
    return prev;
  }

  static void printList(ListNode *head)
  {
    ListNode *curr = head;
    while (curr != nullptr)
    {
      cout << curr->val << " ";
      curr = curr->next;
    }
    cout << "." << endl;
  }
};

int main()
{
  Solution solution;

  // Test case 1
  ListNode *head1 = new ListNode(3);
  head1->next = new ListNode(5);
  head1->next->next = new ListNode(2);
  Solution::printList(solution.reverseList(head1)); // Expected Output: 2 5 3

  // Test case 2
  ListNode *head2 = new ListNode(7);
  Solution::printList(solution.reverseList(head2)); // Expected Output: 7

  // Test case 3
  ListNode *head3 = new ListNode(-1);
  head3->next = new ListNode(0);
  head3->next->next = new ListNode(1);
  Solution::printList(solution.reverseList(head3)); // Expected Output: 1 0 -1

  return 0;
}