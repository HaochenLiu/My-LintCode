/*
094. Binary Tree Maximum Path Sum

Given a binary tree, find the maximum path sum.
The path may start and end at any node in the tree.
Have you met this question in a real interview?
Example
Given the below binary tree:
 1
 / \
2   3


return 6.
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
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        // write your code here
        int res = INT_MIN;
        maxPathSumRe(root, res);
        return res;
    }
    
    int maxPathSumRe(TreeNode* node, int &res) {
        if (!node) return 0;
        int l = maxPathSumRe(node->left, res);
        int r = maxPathSumRe(node->right, res);
        int sum = max(node->val, max(l, r) + node->val);
        res = max(res, max(0, l) + max(0, r) + node->val);
        return sum;
    }
};
