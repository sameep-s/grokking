#include <iostream>
#include <cmath>

using namespace std;

// Define a TreeNode structure with left and right children.
struct TreeNode
{
  int val;         // Value stored in the node.
  TreeNode *left;  // Reference to the left child.
  TreeNode *right; // Reference to the right child.

  // Constructor to initialize a new node with a value.
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
// Time complexity- O(N)
// Space complexity- O(H)

  int closestValue(TreeNode *root, double target)
  {
    int closestVal = root->val;
    
    while(root){
      //  Update smallest number
      if(abs(target - closestVal) > abs(target - root->val)){
        closestVal = root->val;
      }

      if(root->val > target){
        root = root->left;
      }else{
        root = root->right;
      }
    }

    return closestVal;
  }
};

// Main function to test the solution.
int main()
{
  // Constructing a sample BST for testing.
  TreeNode *example1 = new TreeNode(5);
  example1->left = new TreeNode(3);
  example1->left->left = new TreeNode(1);
  example1->left->right = new TreeNode(4);
  example1->right = new TreeNode(8);
  example1->right->left = new TreeNode(6);
  example1->right->right = new TreeNode(9);

  Solution solution;

  // Test the closestValue function with the target value 6.4.
  std::cout << solution.closestValue(example1, 6.4) << std::endl; // Expected output: 6

  // Clean up dynamically allocated memory
  delete example1->right->right;
  delete example1->right->left;
  delete example1->right;
  delete example1->left->right;
  delete example1->left->left;
  delete example1->left;
  delete example1;

  return 0;
}
