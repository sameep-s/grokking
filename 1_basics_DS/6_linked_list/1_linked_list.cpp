#include <iostream>
#include <string>

using namespace std;

// code for a single linked list Node
// template <typename T>
struct Node
{
  string data;
  Node *next;
};

int main()
{
  Node *head = new Node{"Node1"};
  head->next = new Node{"Node 2"};
  head->next->next = new Node{"Node 3"};

  Node *current = head;

  while (current)
  {
    cout << "Node : " << current->data << endl;
    current = current->next;
  }

  return 0;
}