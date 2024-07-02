#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  // Time complexity - O(N) - Traverse each node once.
  // Space complexity - O(h) h - Recursion stack is dependent on height of the tree.

  int depth(TreeNode *Node)
  {
    if (!Node)
      return 0;

    int leftDepth = depth(Node->left);
    int rightDepth = depth(Node->right);

    if (abs(leftDepth - rightDepth) > 1)
      return -1;

    return 1 + max(leftDepth, rightDepth);
  }

  bool isBalanced(TreeNode *root)
  {
    return depth(root) != -1;
  }
};

int main()
{
  // Test example 1
  TreeNode *example1 = new TreeNode(3);
  example1->left = new TreeNode(9);
  example1->right = new TreeNode(20);
  example1->right->left = new TreeNode(15);
  example1->right->right = new TreeNode(7);

  // Test example 2
  TreeNode *example2 = new TreeNode(1);
  example2->left = new TreeNode(2);
  example2->left->left = new TreeNode(3);
  example2->left->left->left = new TreeNode(4);
  example2->right = new TreeNode(5);

  Solution solution;

  cout << solution.isBalanced(example1) << endl; // Expected output: 1 (true)
  cout << solution.isBalanced(example2) << endl; // Expected output: 0 (false)

  // Free allocated memory (avoid memory leak)
  delete example1->right->right;
  delete example1->right->left;
  delete example1->right;
  delete example1->left;
  delete example1;

  delete example2->right;
  delete example2->left->left->left;
  delete example2->left->left;
  delete example2->left;
  delete example2;

  return 0;
}