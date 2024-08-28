#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the height of the binary tree
int height(TreeNode* root) {
    if (root == NULL) {
        return -1; // Height of an empty tree is -1 (or you can use 0 for a leaf node)
    }

    // Recursively calculate the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    // Return the greater of the two heights plus one
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Main function to demonstrate the height calculation
int main() {
    // Create a simple binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->right = createNode(6);

    // Calculate and print the height of the tree
    int treeHeight = height(root);
    printf("Height of the binary tree: %d\n", treeHeight);
    
    // Free allocated memory (not shown here for simplicity)
    // Implement proper cleanup in real code

    return 0;
}
