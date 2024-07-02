#include <iostream>
#include <algorithm>
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
  //  Time complexity - O(N) - Beacuse we have to traverse each node once
  //  Space complexity - O(H) - Because the depth of recursion stack is dependent on depth of tree
  int maxDepth(TreeNode *root)
  {
    // base case
    if (!root)
      return 0;

    // Recursive Case
    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
  }
};

int main()
{
  Solution solver;

  // Example 1
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  root1->left->left = new TreeNode(4);
  root1->left->right = new TreeNode(5);
  std::cout << solver.maxDepth(root1) << std::endl; // Expected output: 3

  // Example 2
  TreeNode *root2 = new TreeNode(1);
  root2->right = new TreeNode(2);
  root2->right->right = new TreeNode(3);
  std::cout << solver.maxDepth(root2) << std::endl; // Expected output: 3

  // Example 3
  TreeNode *root3 = new TreeNode(1);
  root3->left = new TreeNode(2);
  root3->right = new TreeNode(3);
  root3->left->left = new TreeNode(4);
  root3->left->right = new TreeNode(7);
  root3->left->right->right = new TreeNode(9);
  std::cout << solver.maxDepth(root3) << std::endl; // Expected output: 4

  // Free the memory allocated for nodes
  delete root1->left->right;
  delete root1->left->left;
  delete root1->left;
  delete root1->right;
  delete root1;

  delete root2->right->right;
  delete root2->right;
  delete root2;

  delete root3->left->right->right;
  delete root3->left->right;
  delete root3->left->left;
  delete root3->left;
  delete root3->right;
  delete root3;

  return 0;
}
