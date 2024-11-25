#include <bits/stdc++.h>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Time complexity - O(logN) in a skewed tree 0(h) where h is the height of the tree
    // Space complexity - O(logN)
    TreeNode *insert(TreeNode *root, int value)
    {
        // Base case
        if (root == nullptr)
            return new TreeNode(value);

        // Recursive case
        if (root->val > value)
            root->left = insert(root->left, value);
        else if (root->val < value)
            root->right = insert(root->right, value);

        return root;
    }
};

void printBST(TreeNode *node)
{
    // Base case
    if (node == nullptr)
        return;

    // Recursive case
    printBST(node->left);
    printf("%d\n", node->val);
    printBST(node->right);
}

int main()
{
    // Example inputs
    TreeNode *root = new TreeNode(4);

    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    int values[] = {5, 4, 2, 25};
    int numValues = sizeof(values) / sizeof(values[0]);

    Solution bstInsertion;

    // Insert nodes into the BST
    for (int i = 0; i < numValues; i++)
    {
        root = bstInsertion.insert(root, values[i]);
    }

    // Print the updated BST
    std::cout << "BST After Insertion:\n";
    printBST(root);

    return 0;
}
