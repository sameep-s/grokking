template <class T>
class Node
{
  T data;

  Node<T> *left;
  Node<T> *right;

  // Constructor
  Node() : data(0), left(nullptr), right(nullptr) {}
  Node(T val) : data(val), left(nullptr), right(nullptr) {}
};

// -------------------- Operations --------------------
// Insert
// Delete
// Search
// Update
// In-order traversal - left, curr, right - order in which tree gets filled
// Pre-order traversal -  curr, left, right
// Post-order traversal - left, right, curr

template <class T>
class BST
{
private:
  Node<T> *root;

  void inOrderHelper(Node<T> *p);
  void preOrderHelper(Node<T> *p);
  void postOrderHelper(Node<T> *p);

  Node<T> *findMin(Node<T> *node);            // Helper function to find the min val in the Tree
  Node<T> *deleteNode(Node<T> *root, T node); // Delete the targeted val in the Tree

public:
  BST() : root(nullptr) {}

  void insert(T node);
  void deleteMethod(T node);
  bool search(T node);

  void inOrder();   // left->center->right
  void preOrder();  // center->left->right
  void postOrder(); // left->right->center
};

// Helper function to insert element in binary tree
template <class T>
void BST<T>::insert(T node)
{
  // Insert an element in the BST : follow the rules of Binary Tree
  // Step 1: If root is nullPtr ie tree is empty, assign new node to root
  // Step 2: init two pointers parent and current, assign parent to nullPtr an current to root
  // Step 3: find the parent one level above the leafs, then add node to that parent

  Node<T> *newNode = new Node<T>(node);

  if (root == nullptr)
  {
    root = newNode;
  }
  else
  {
    Node<T> *current = newNode;
    Node<T> *parent = nullptr;

    while (current != nullptr)
    {
      parent = current;
      if (node < current->data)
        current = current->left;
      else
        current = current->right;
    }

    if (node > parent->data)
      parent->right = node;
    else
      parent->left = node;
  }
}

// Delete a node from a binary search tree
template <class T>
Node<T> *BST<T>::deleteNode(Node<T> *root, T node)
{
  if (root == nullptr)
    return root;

  if (node > root->data)
  {
    root->right = deleteNode(root->right, node);
  }
  else if (node < root->data)
  {
    root->left = deleteNode(root->left, node);
  }
  else
  {
    // handle for one or less children
    if (root->left == nullptr)
    {
      Node<T> *temp = root->right;
      delete root;
      return temp;
    }
    else if (root->right == nullptr)
    {
      Node<T> *temp = root->left;
      delete root;
      return temp;
    }

    // handle for more children
    // find in-order min
    Node<T> *temp = findMin(root);
    root->data = temp->data;

    root->right = deleteNode(root->right, temp->data);
  }

  return root;
}

// Helper function to find min element in binary tree
template <class T>
Node<T> *BST<T>::findMin(Node<T> *node)
{

  while (node->left != nullptr)
  {
    node = node->left;
  }

  return node;
}

// Searching
template <class T>
bool BST<T>::search(T node)
{
  Node<T> *curr = root;

  while (curr != nullptr)
  {
    if (curr->data == node)
      return true;
    else if (node > curr->data)
      curr = curr->right;
    else
      curr = curr->left;
  }

  return false;
}

// In-order Traversal - l, root, right
// Post-oreder Traversal - l, right, root
// Pre-order Traversal -  root, l, right
