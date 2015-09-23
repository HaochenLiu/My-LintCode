/*
070. Binary Tree Level Order Traversal II

Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
Have you met this question in a real interview?
Example
Given binary tree {3,9,20,#,#,15,7},
   3
   / \
  9  20
    /  \
   15   7


 
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
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
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        // write your code here
        vector<vector<int>> res;
        vector<int> record;
        if(root == NULL) return res;
        queue<TreeNode*> current;
        queue<TreeNode*> next;
        current.push(root);
        while(!current.empty()) {
            while(!current.empty()) {
                TreeNode* node = current.front();
                current.pop();
                record.push_back(node->val);
                if(node->left) {
                    next.push(node->left);
                }
                if(node->right) {
                    next.push(node->right);
                }
            }
            res.push_back(record);
            record.clear();
            swap(current, next);
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
