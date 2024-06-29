#include <iostream>

using namespace std;

// List Node
struct ListNode
{
  int val;
  ListNode *next;
};

class Solution
{
private:
  ListNode *head;

public:
  // Constructor
  Solution() : head(nullptr) {}

  // Function to insert value at front of the linked list
  void insert(int val)
  {
    ListNode *newListNode = new ListNode{val};
    newListNode->next = head;
    head = newListNode;
  }

  // insert after a particular Node
  void insertAfter(ListNode *prevNode, int key)
  {
    // if prev node is null
    if (prevNode == nullptr)
    {
      cout << "Previous node cannot be NULL" << endl;
      return;
    }

    ListNode *newNode = new ListNode{key};
    newNode->next = prevNode->next;
    prevNode->next = newNode;
  }

  // Delete Node from the linked list
  void deleteNode(int key)
  {
    ListNode *temp = head, *prev = nullptr;

    // If the value is present in head
    if (temp != nullptr && temp->val == key)
    {
      head = temp->next;
      delete temp;
      return;
    }

    // find element in linkedlist
    while (temp != nullptr && temp->val != key)
    {
      prev = temp;
      temp = temp->next;
    }

    // If key was not present in the list
    if (temp == nullptr)
      return;

    // Unlink the node from the list
    prev->next = temp->next;
    delete temp;

    return;
  }

  // Search element in the linkedlist
  bool search(int key)
  {
    ListNode *curr = head;
    while (curr != nullptr)
    {
      if (curr->val == key)
        return true;
      curr = curr->next;
    }

    return false;
  }
};

// Main function to test the Solution class
int main()
{
  Solution list; // Create an empty list

  // Insert nodes into the list
  list.insert(1);
  list.insert(2);
  list.insert(3);

  // Search for a key in the list
  std::cout << "Search 2: " << list.search(2) << std::endl; // 1 (True)

  // Delete a node from the list by key
  list.deleteNode(2);

  // Check if the key is still present in the list
  std::cout << "Search 2: " << list.search(2) << std::endl; // 0 (False)

  return 0;
}