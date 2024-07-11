#include <iostream>
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
public:
  int rangeSumBST(TreeNode *root, int L, int R)
  {
    // Use BST property if val > R then traverse left else traverse right if equal or in range
    // go both ways

    // ---------------------------------------------- Base case
    if (!root)
    {
      return 0;
    }

    // ---------------------------------------------- Recursive case
    if (root->val < L) // if val is less than left
      return rangeSumBST(root->right, L, R);

    if (root->val > R) // if val is greater than right
      return rangeSumBST(root->left, L, R);

    return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
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
  cout << solution.rangeSumBST(example1, 7, 15) << endl; // Expected output: 32

  // Remember to delete allocated memory to prevent memory leaks
  delete example1->right->right;
  delete example1->right;
  delete example1->left->right;
  delete example1->left->left;
  delete example1->left;
  delete example1;

  return 0;
}
