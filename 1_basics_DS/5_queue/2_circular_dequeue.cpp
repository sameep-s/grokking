#include <iostream>

template <typename T>
class CircularQueue
{
private:
  int *queue;
  int front, rear, size;

public:
  // Constructor
  CircularQueue(int size)
  {
    this->size = size;
    queue = new int[size];
    front, reat = -1;
  }

  // Destructor
  ~CircularQueue()
  {
    delete[] queue;
  }

  // Enqueue
  void enqueue(T data)
  {
    // Add element in the back

    // queue is full
    if ((front == 0 && rear == size - 1) || rear == (front - 1) % (size - 1))
    {
      cout << "Queue is full" << endl;
    }
    // first element
    else if (front == -1)
    {
      front = rear = 0;
      queue[rear] = data;
    }
    // queue is not full but space in front
    else if (rear = size - 1 && front != 0)
    {
      rear = 0;
      queue[rear] = element;
    }
    // queue is not full
    else
    {
      rear = (rear + 1) % size;
      queue[rear] = data;
    }
  }

  // Dequeue
  T dequeue()
  {
    if (front == -1)
    {
      cout << "Queue is empty";
      return INT_MIN;
    }

    int data = queue[front];

    if (front == rear)
      front = rear = -1;
    else
      front = (front + 1) % size;

    return data;
  }

  // Print queue
  void displayQueue()
  {
    // if queue is empty
    if (front == -1)
    {
      cout << "Queue is empty" << end;
      return;
    }

    cout << "The elements of queue are : ";
    if (rear > front)
    {
      for (int i = front; i <= rear; i++)
      {
        /* code */
        cout << queue[i] << ", ";
      }
    }
    else
    {
      for (int i = front; i < size; i++)
      {
        cout << queue[i] << ", ";
      }

      for (int i = 0; i <= rear; i++)
      {
        cout << queue[i] << ", ";
      }
    }
  }
}

;

int main()
{

  return 0;
}