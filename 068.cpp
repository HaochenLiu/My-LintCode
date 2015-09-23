/*
068. Binary Tree Postorder Traversal

Given a binary tree, return the postorder traversal of its nodes' values.
Have you met this question in a real interview?
Example
Given binary tree {1,#,2,3},
  1
    \
     2
    /
   3


 
return [3,2,1].
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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(root == NULL) return res;
        stack<TreeNode*> current;
        current.push(root);
        while(!current.empty()) {
            TreeNode* node = current.top();
            current.pop();
            res.insert(res.begin(), node->val);
            if(node->left) {
                current.push(node->left);
            }
            if(node->right) {
                current.push(node->right);
            }
        }

        return res;
    }
};
