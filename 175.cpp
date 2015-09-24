/*
175. Invert Binary Tree

Invert a binary tree.
Have you met this question in a real interview?
Example
 1         1
 / \       / \
2   3  => 3   2
   /       \
  4         4


Challenge
Do it in recursion is acceptable, can you do it without recursion?
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void invertBinaryTree(TreeNode *root) {
        // write your code here
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        if(root->left == NULL && root->right != NULL ) {
            invertBinaryTree(root->right);
            root->left = root->right;
            root->right = NULL;
            return;
        }

        if(root->left != NULL && root->right == NULL ) {
            invertBinaryTree(root->left);
            root->right = root->left;
            root->left = 0;
            return;
        }

        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
        TreeNode* node = root->left;
        root->left = root->right;
        root->right = node;

        return;
    }
};
