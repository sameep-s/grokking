#include <iostream>
#include <stack>
#include <string>
using namespace std;

// A Singular node in Queue
template <typename T>
class Node
{
public:
  T data;
  Node *next;

  Node(T data) : data(data), next(nullptr) {}
};

// Implementation of queue FIFO
template <typename T>
class Queue
{
private:
  Node<T> *front;
  Node<T> *rear;
  int size;

public:
  // Constructor
  Queue() : front(nullptr), rear(nullptr), size(0){};

  // Destructor
  ~Queue()
  {
    while (!isEmpty())
    {
      dequeue();
    }
  }

  // Enqueue - add in the back
  void enqueue(T data)
  {
    Node<T> *newNode = new Node<T>(data);
    if (rear == nullptr)
    {
      front = rear = newNode;
    }
    else
    {
      rear->next = newNode;
      rear = newNode;
    }
    size++;
  }

  // Dequeue - remove from the front
  T dequeue()
  {

    //---------------------   // Dequeue Steps
    // If front->next is nullPtr then queue is empty return reference pointer
    // Create a temp variable store front into it
    // put front = front->next
    // if front -> nullPtr then put rear -> nullPtr
    // Create a variable T data and store temp-data into it
    // delete temp
    // size--
    // return temp;

    Node<T> *temp = front;

    if (front == nullptr)
    {
      return T();
    }

    Node<T> *temp = front;
    front->front->next;

    if (front->next == nullptr)
    {
      rear = nullptr;
    }

    T data = temp->data;
    size--;
    delete temp;
    return data;
  }

  // Peek
  T peek()
  {
    if (front == nullptr)
    {
      return T();
    }

    return front->data;
  }

  // get Size
  int get_size()
  {
    return size;
  }

  // isEmpty
  bool isEmpty()
  {
    return size == 0;
  }
};

int main()

{
  Queue<int> q;

  cout << q.isEmpty() << endl;
  return 0;
}