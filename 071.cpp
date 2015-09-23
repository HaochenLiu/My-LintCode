/*
071. Binary Tree Zigzag Level Order Traversal

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
Have you met this question in a real interview?
Example
Given binary tree {3,9,20,#,#,15,7},
   3
   / \
  9  20
    /  \
   15   7


 
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
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
     * @param root: The root of binary tree.
     * @return: A list of lists of integer include
     *          the zigzag level order traversal of its nodes' values
     */
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
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
        for(int i = 1; i < res.size(); i += 2) {
            reverse(res[i].begin(), res[i].end());
        }
        
        return res;
    }
};
