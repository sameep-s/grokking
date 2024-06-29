#include <stack>
#include <stdexcept> // standard cpp exception library

template <typename T>
class MyStack
{
private:
  std::stack<T> stack; // create a private member varibale of type std::stack<T> to store stack elements

public:
  // check if stack is empty
  bool isEmpty()
  {
    return stack.empty();
  }

  // push elements into stack
  void push(T data)
  {
    stack.push(data);
  }

  // pop
  T pop()
  {
    if (isEmpty())
    {
      throw std::out_of_range("Stack is empty"); // throw exception if the stack is empty
    }
    T top = stack.top();
    stack.pop();

    return top;
  }

  // peek
  T peek()
  {
    if (isEmpty())
    {
      throw std::out_of_range("Stack is empty");
    }
    T top = stack.top();
    return top;
  }
};

int main()
{

  return 0;
}