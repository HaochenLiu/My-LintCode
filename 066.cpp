/*
066. Binary Tree Preorder Traversal

Given a binary tree, return the preorder traversal of its nodes' values.
Have you met this question in a real interview?
Example
Given binary tree {1,#,2,3}:
1
 \
  2
 /
3


return [1,2,3].
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
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            res.push_back(node->val);
            if(node->right) {
                st.push(node->right);
            }
            if(node->left) {
                st.push(node->left);
            }
        }
        
        return res;
    }
};
