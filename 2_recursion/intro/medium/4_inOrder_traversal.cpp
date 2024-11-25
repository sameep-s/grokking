#include <stdio.h>
#include <vector>
using namespace std;

// Inorder - l, r, val
// Preorder - val, l, r
// Postorder - l, r, val

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Time complexity - O(logN) - N number of nodes
    // Space complexity - O(logN)
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> nodes;
        inorder(root, nodes);

        return nodes;
    }

    // Inorder Traversal
    void inorder(TreeNode *root, vector<int> &nodes)
    {
        // Base case
        if (!root)
            return;

        // Recursive case
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
};

int main()
{
    // Example inputs
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    Solution inorderTraversal;
    std::vector<int> result = inorderTraversal.inorderTraversal(root);

    printf("Inorder Traversal: ");
    for (int val : result)
        printf("%d ", val);

    printf("\n");

    return 0;
}