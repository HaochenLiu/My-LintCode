/*
164. Unique Binary Search Trees II

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
Have you met this question in a real interview?
Example
Given n = 3, your program should return all 5 unique BST's shown below.
  1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
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
private:
    vector<TreeNode*> createTree(int start, int end) {
        vector<TreeNode*> res;
        if(start > end) {
            res.push_back(NULL);
            return res;
        }
        if(start == end) {
            TreeNode* root = new TreeNode(start);
            root->left = NULL;
            root->right = NULL;
            res.push_back(root);
            return res;
        }
        for(int i = start; i <= end; i++) {
            vector<TreeNode*> leftTree = createTree(start, i - 1);
            vector<TreeNode*> rightTree = createTree(i + 1, end);
            for(int j = 0; j < leftTree.size(); j++) {
                for(int k = 0; k < rightTree.size(); k++) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftTree[j];
                    root->right = rightTree[k];
                    res.push_back(root);
                }
            }
        }
        return res;
    }

public:
    /**
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        // write your code here
        return createTree(1, n);
    }
};
