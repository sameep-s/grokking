#include <iostream>
#include <vector>
using namespace std;

// Definition for the TreeNode structure.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
private:
  int result = 0;
  int count = 0;

  void traverseInOrder(TreeNode *root, int key)
  {
    if (!root || count > key)
      return;

    traverseInOrder(root->left, key);

    count++;
    if (count == key)
      result = root->val;
    return;

    traverseInOrder(root->right, key);
  }

public:
  // Time complexity - O(N)
  // Space complexity - O(H)
  Solution() : count(0), result(0) {};

  int kthSmallest(TreeNode *root, int k)
  {
    traverseInOrder(root, k);
    return result;
  }
};

int main()
{
  // Test using the examples provided
  TreeNode *example1 = new TreeNode(10);
  example1->left = new TreeNode(5);
  example1->left->left = new TreeNode(3);
  example1->left->right = new TreeNode(7);
  example1->right = new TreeNode(15);
  example1->right->right = new TreeNode(18);

  Solution solution;
  cout << solution.kthSmallest(example1, 2) << endl;

  // Remember to delete allocated memory to prevent memory leaks
  delete example1->right->right;
  delete example1->right;
  delete example1->left->right;
  delete example1->left->left;
  delete example1->left;
  delete example1;

  return 0;
}
