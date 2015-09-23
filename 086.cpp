/*
086. Binary Search Tree Iterator

Design an iterator over a binary search tree with the following rules:
Elements are visited in ascending order (i.e. an in-order traversal)
next() and hasNext() queries run in O(1) time in average.
Have you met this question in a real interview?
Example
For the following binary search tree, in-order traversal by using iterator is [1, 6, 10, 11, 12]
  10
 /    \
1      11
 \       \
  6       12


Challenge
Extra memory usage O(h), h is the height of the tree.
Super Star: Extra memory usage O(1)
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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
private:
    std::stack<TreeNode*> stack;

public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        while (root != NULL) {
            stack.push(root);
            root = root->left;
        }
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return (!stack.empty());
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode* cur = stack.top();
        TreeNode* res = cur;
        stack.pop();
        cur = cur->right;
        while(cur != NULL) {
            stack.push(cur);
            cur = cur->left;
        }
        return res;
    }
};
