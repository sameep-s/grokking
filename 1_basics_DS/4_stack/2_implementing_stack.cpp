#include <stdexcept>

// Implement stack using LinkedLists
template <typename T2>
class Stack_LL
{
private:
  struct Node
  {
    T2 data;
    node *next;
  }

  Node *top;

public:
  // constructor - point top->next towards nullPtr, indicating an empty stack
  Stack_LL() : top(nullptr){};

  // destructor - free memory by deleting all the nodes of the linked list
  ~Stack_LL()
  {
    while (top)
    {
      Node *oldTop = top;
      top = top->next;
      delete oldTop;
    }
  }

  // push - push new element to the top
  void push(T data)
  {
    Node *newTop = new Node; // create a new node newTop
    newTop->data = data;     // set newTop-> as the param
    newTop->next = top;      // point newTop towards the top pointer

    top = newTop; // make newTop as top
  }

  // pop
  T2 pop()
  {
    if (!top)
    {
      throw std::out_of_range("Stack underflow: stack empty")
    }

    T item = top->data;
    Node *oldTop = top;
    top = top->next;
    delete oldTop;

    return item;
  }

  // peek
  T2 peek()
  {
    if (!top)
    {
      throw std::out_of_range("Stack is empty"); // is stack is empty throw an exception
    }

    return top->data;
  }

  // isEmpty - check if the stack is Empty
  bool isEmpty()
  {
    return top->next == nullptr; // if top-next points to nullPtr return true
  }
};

// Implement stacks using arrays
template <typename T>
class Stack
{
private:
  // constructor that takes max size of stack as a parameter
  T *stack; // pointer to array that will store stack elements
  int top;  // index of the top most element of the stack
  int size; // max size of the stack

public:
  // Constructor of stack
  Stack(int size) : size(size)
  {
    stack = new T[size];
    top = -1;
  }

  // Destructor to release dynamically allocated memory when the object is destroyed
  ~Stack()
  {
    delete[] Stack;
  }

  // isEmpty
  bool isEmpty()
  {
    return top == -1;
  }

  // push
  void push(T data)
  {
    if (top == size - 1)
    {
      throw std::out_of_range("Stack is full");
    }
    stack[++top] = data; // increment to top of the stack
  }

  // pop
  T pop()
  {
    if (top == -1)
    {
      throw std::out_of_range("Stack is empty");
    }
    T top = stack[top]; // get the top element of the stack
    stack[top--] = T(); // reset the element to default value

    return top; // return popped item
  }

  // peek
  T peek()
  {
    if (isEmpty())
    {
      throw std::out_of_range("Stack is Empty");
    }
    return stack[top]; // return top item
  }
};

// Applications of stack

// 1. Memory management - this is how the computer remembers which function to run, eg. recursion.
// 2. Expression Evaluation and syntax parsing - eg:- 3+ 4*5 BODMAS can be applied using stacks and that's how code editors check if syntax is valid using stacks.
// 3. Backtracking algorithims - 8 queens problems, Sudoku solver uses backtracking.
// 4. DFS (Depth First Search) - pushes unvisited nodes into the stack and remove them once visited.
// 5. Web page history in browsers - URL is pushed into stack, whenever the user visits a web page.