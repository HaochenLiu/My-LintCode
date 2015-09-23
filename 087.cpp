/*
087. Remove Node in Binary Search Tree

Given a root of Binary Search Tree with unique value for each node.  Remove the node with given value. If there is no such a node with given value in the binary search tree, do nothing. You should keep the tree still a binary search tree after removal.
Have you met this question in a real interview?
Example
Given binary search tree:
          5
       /    \
    3          6
 /    \
2       4
Remove 3, you can either return:
          5
       /    \
    2          6
      \
         4
or :
          5
       /    \
    4          6
 /   
2
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
     * @param root: The root of the binary search tree.
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode* removeNode(TreeNode* root, int value) {
        // write your code here
        if(root == NULL) return NULL;
        TreeNode* parent = root;
        TreeNode* cur;
        if(root->val == value) {
            if(root->left == NULL) {
                TreeNode* node = root->right;
                delete(root);
                return node;
            } else if(root->left->right == NULL) {
                root->left->right = root->right;
                TreeNode* node = root->left;
                delete(root);
                return node;
            } else {
                TreeNode* node = root->left;
                while(node->right) {
                    node = node->right;
                }
                node->right = root->right;
                node = root->left;
                delete(root);
                return node;
            }
        } else if(root->val < value) {
            cur = root->right;
        } else {
            cur = root->left;
        }

        if(cur == NULL) {
            return root;
        }

        while(cur) {
            if(cur->val == value) {
                if(cur->left == NULL) {
                    if(parent->left == cur) {
                        parent->left = cur->right;
                    } else {
                        parent->right = cur->right;
                    }
                    delete(cur);
                    return root;
                } else if(cur->right == NULL) {
                    if(parent->left == cur) {
                        parent->left = cur->left;
                    } else {
                        parent->right = cur->left;
                    }
                    delete(cur);
                    return root;
                }
            } else if(cur->val < value) {
                parent = cur;
                cur = cur->right;
            } else {
                parent = cur;
                cur = cur->left;
            }
        }
        
        return root;
    }
};
