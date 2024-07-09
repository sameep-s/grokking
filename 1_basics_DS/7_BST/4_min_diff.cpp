#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// TreeNode structure to represent the Binary Search Tree nodes.
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{

private:
  vector<int> v;

  // Inorder Travesal
  void inOrderTraversal(TreeNode *node)
  {
    if (!node)
      return;

    inOrderTraversal(node->left);
    v.push_back(node->val);
    inOrderTraversal(node->right);
  }

public:
  // Find the min diff
  int minDiffInBST(TreeNode *node)
  {
    // clear values in vector
    v.clear();

    int minVal = INT_MAX;

    // Step 1: InorderTraversal
    inOrderTraversal(node);

    // Step 2: Iterate through array
    for (int i = 0; i < v.size() - 1; i++)
    {
      int calcMin = abs(v[i] - v[i + 1]);
      minVal = min(minVal, calcMin);
    }

    // Step 2: return min
    return minVal;
  }
};

int main()
{
  // First test case
  TreeNode *example1 = new TreeNode(4);
  example1->left = new TreeNode(2);
  example1->left->left = new TreeNode(1);
  example1->left->right = new TreeNode(3);
  example1->right = new TreeNode(6);

  // Second test case
  TreeNode *example2 = new TreeNode(40);
  example2->right = new TreeNode(70);
  example2->right->left = new TreeNode(50);
  example2->right->right = new TreeNode(90);

  Solution solution;

  std::cout << solution.minDiffInBST(example1) << std::endl; // Expected output: 1
  std::cout << solution.minDiffInBST(example2) << std::endl; // Expected output: 10 (50-40)

  // Clean-up the allocated memory.
  delete example1->left->left;
  delete example1->left->right;
  delete example1->left;
  delete example1->right;
  delete example1;
  delete example2->right->left;
  delete example2->right->right;
  delete example2->right;
  delete example2;

  return 0;
}