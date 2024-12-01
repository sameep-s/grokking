#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int val) : val(val), next(nullptr) {}
};

class Solution
{
public:
    // Time complexity - log(N)
    // Space complexity - log(N)
    ListNode *removeNodes(ListNode *head, int target)
    {
        //   Base case
        if (!head)
            return nullptr;

        //   Recursive  case
        if (head->val != target)
            head->next = removeNodes(head->next, target);
        else
            head = head->next;

        return head;
    }

    void printLinkedList(ListNode *start)
    {
        if (!start)
        {
            printf("\n");
            return;
        }

        printf("%d ", start->val);
        printLinkedList(start->next);
    }
};

int main()
{
    Solution sol;

    // Example 1
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(2);

    std::cout << "Original Linked List 1: ";
    sol.printLinkedList(head1);

    // Remove nodes with value 2 from linked list
    ListNode *modifiedHead1 = sol.removeNodes(head1, 2);
    std::cout << "Modified Linked List 1: ";
    sol.printLinkedList(modifiedHead1);
    printf("\n");

    // Example 2
    ListNode *head2 = new ListNode(2);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(2);
    head2->next->next->next = new ListNode(2);
    head2->next->next->next->next = new ListNode(2);

    std::cout << "Original Linked List 2: ";
    sol.printLinkedList(head2);

    // Remove nodes with value 2 from linked list
    ListNode *modifiedHead2 = sol.removeNodes(head2, 2);
    std::cout << "Modified Linked List 2: ";
    sol.printLinkedList(modifiedHead2);
    printf("\n");

    // Example 3
    ListNode *head3 = new ListNode(1);
    head3->next = new ListNode(3);
    head3->next->next = new ListNode(5);
    head3->next->next->next = new ListNode(7);

    std::cout << "Original Linked List 3: ";
    sol.printLinkedList(head3);

    // Remove nodes with value 2 from linked list
    ListNode *modifiedHead3 = sol.removeNodes(head3, 2);
    std::cout << "Modified Linked List 3: ";
    sol.printLinkedList(modifiedHead3);
    printf("\n");

    return 0;
}
