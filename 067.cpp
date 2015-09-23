/*
067. Binary Tree Inorder Traversal

Given a binary tree, return the inorder traversal of its nodes' values.
Have you met this question in a real interview?
Example
Given binary tree {1,#,2,3},
  1
    \
     2
    /
   3


 
return [1,3,2].
Challenge
Can you do it without recursion?
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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(!st.empty() || node) {
            if(node) {
                st.push(node);
                node = node->left;
            } else {
                node = st.top();
                st.pop();
                res.push_back(node->val);
                node = node->right;
            }
        }
        
        return res;
    }
};
