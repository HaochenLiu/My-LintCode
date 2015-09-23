/*
095. Validate Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Have you met this question in a real interview?
Example
An example:
 2
 / \
1   3
   /
  4
   \
    5


The above binary tree is serialized as {2,1,3,#,#,4,#,#,5} (in level order).
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
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        if(!isValidBST(root->left)) return false;
        if(!isValidBST(root->right)) return false;
        if(root->left) {
            TreeNode* node = root->left;
            while(node->right) {
                node = node->right;
            }
            if(node->val >= root->val) {
                return false;
            }
        }

        if(root->right) {
            TreeNode* node = root->right;
            while(node->left) {
                node = node->left;
            }
            if(node->val <= root->val) {
                return false;
            }
        }

        return true;
    }
};
