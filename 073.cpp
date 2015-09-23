/*
073. Construct Binary Tree from Preorder and Inorder Traversal

Given preorder and inorder traversal of a tree, construct the binary tree.
Have you met this question in a real interview?
Example
Given in-order [1,2,3] and pre-order [2,1,3], return a tree:
 2
 / \
1   3


Note
You may assume that duplicates do not exist in the tree.
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
     *@param preorder : A list of integers that preorder traversal of a tree
     *@param inorder : A list of integers that inorder traversal of a tree
     *@return : Root of a tree
     */
private:
    TreeNode *buildTreeRecur(vector<int>::iterator pbegin, vector<int>::iterator pend, vector<int>::iterator ibegin, vector<int>::iterator iend) {
        if(pbegin == pend) return NULL;
        TreeNode* node = new TreeNode(*pbegin);
        vector<int>::iterator it = find(ibegin, iend, *pbegin);
        node->left = buildTreeRecur(pbegin + 1, pbegin + 1 + (it - ibegin), ibegin, it);
        node->right = buildTreeRecur(pbegin + 1 + (it - ibegin), pend, it + 1, iend);
        
        return node;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // write your code here
        return buildTreeRecur(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
};
