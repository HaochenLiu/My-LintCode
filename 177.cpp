/*
177. Convert Sorted Array to Binary Search Tree With Minimal Height

Given a sorted (increasing order) array, Convert it to create a binary tree with minimal height.
Have you met this question in a real interview?
Example
Given [1,2,3,4,5,6,7], return
    4
   /   \
  2     6
 / \    / \
1   3  5   7


Note
There may exist multiple valid solutions, return any of them.
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
    TreeNode* sortedArrayToBSTRecur(vector<int>& nums, int start, int end) {
        if(start > end) return NULL;
        int mid = start + (end - start + 1) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTRecur(nums, start, mid - 1);
        root->right = sortedArrayToBSTRecur(nums, mid + 1, end);
        return root;
    }

public:
    /**
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // write your code here
        if(nums.size() == 0) return NULL;
        return sortedArrayToBSTRecur(nums, 0, nums.size() - 1);
    }
};
