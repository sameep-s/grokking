#include <iostream>
#include <vector>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Time complexity  - O(min(m,n))
    // Space complexity  - O(min(m,n))

    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        // Base case 
        if(!t1) return t2;
        if(!t2) return t1;
        
        // Recursive case 
        TreeNode* newNode = new TreeNode(t1-> val + t2->val);

        // Recursive call for left and right children.
        newNode->left = mergeTrees(t1->left, t2->left);
        newNode->right = mergeTrees(t1->right, t2->right);

        return newNode;
    }
};


void printInOrder(TreeNode* root){
    if(!root ) return;

    printInOrder(root->left);
    cout<< root->val <<endl;
    printInOrder(root->right);
}


int main() {
    // Test the algorithm with the provided input
    Solution solution;

    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);
    tree1->left->left = new TreeNode(4);
    tree1->left->right = new TreeNode(5);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    tree2->left->right = new TreeNode(5);

    TreeNode* mergedTree = solution.mergeTrees(tree1, tree2);

    // Print the merged tree using inorder traversal
    printInOrder(mergedTree);
    std::cout << std::endl;  // for a newline after traversal

    // Cleanup allocated memory
    // NOTE: For simplicity, we're not implementing a full tree destructor here.
    // In a complete program, you'd want to free all nodes to prevent memory leaks.
    delete tree1->left->left;
    delete tree1->left->right;
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left->right;
    delete tree2->left;
    delete tree2->right;
    delete tree2;
    delete mergedTree;  // This will only delete the root; again, a full tree destructor would be needed.
}

