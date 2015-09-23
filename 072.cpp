/*
072. Construct Binary Tree from Inorder and Postorder Traversal

Given inorder and postorder traversal of a tree, construct the binary tree.
Have you met this question in a real interview?
Example
Given inorder [1,2,3] and postorder [1,3,2], return a tree:
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
     *@param inorder : A list of integers that inorder traversal of a tree
     *@param postorder : A list of integers that postorder traversal of a tree
     *@return : Root of a tree
     */
private:
    TreeNode *buildTreeRecur(vector<int>::iterator pbegin, vector<int>::iterator pend, vector<int>::iterator ibegin, vector<int>::iterator iend) {
        if(pbegin == pend) return NULL;
        TreeNode* node = new TreeNode(*(pend - 1));
        vector<int>::iterator it = find(ibegin, iend, *(pend - 1));
        node->left = buildTreeRecur(pbegin, pbegin + (it - ibegin), ibegin, it);
        node->right = buildTreeRecur(pbegin + (it - ibegin), pend - 1, it + 1, iend);
        
        return node;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // write your code here
        return buildTreeRecur(postorder.begin(), postorder.end(), inorder.begin(), inorder.end());
    }
};
