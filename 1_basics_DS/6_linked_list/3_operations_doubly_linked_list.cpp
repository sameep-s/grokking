#include <iostream>
using namespace std;

struct DLNode
{
  int val;
  DLNode *next;
  DLNode *prev;
};

class DoublyLinkedList
{
private:
  DLNode *head;

public:
  DoublyLinkedList() : head(nullptr) {}

  // Insert a new node with the given value at the beginning of the list.
  void insert(int key)
  {
    DLNode *newNode = new DLNode{key};
    newNode->next = head;

    if (head != nullptr)
      head->prev = newNode;

    head = newNode;
  }

  void insertAfter(DLNode *prevNode, int key)
  {
    if (prevNode != nullptr)
    {
      cout << "The given node cannot be null" << endl;
      return;
    }

    DLNode *newNode = new DLNode{key};

    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;

    if (newNode->next != nullptr)
      newNode->next->prev = newNode;
  }

  // Delete node
  void deleteNode(int key)
  {
    // If head node contains the element
    DLNode *temp = head;

    while (temp != nullptr)
    {
      if (temp->val == key)
      {
        if (temp->prev != nullptr)
          temp->prev->next = temp->next;
        else
          head = temp->next;

        if (temp->next != nullptr)
          temp->next->prev = temp->prev;
        delete temp;

        return;
      }

      temp = temp->next;
    }
  }

  // Search they key in the List
  bool search(int key)
  {
    DLNode *curr = head;
    while (curr != nullptr)
    {
      if (curr->val == key)
        return true;
      curr = curr->next;
    }

    return false;
  }
};

int main()
{

  return 0;
}