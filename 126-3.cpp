/*
126. Max Tree

Given an integer array with no duplicates. A max tree building on this array is defined as follow:
The root is the maximum number in the array
The left subtree and right subtree are the max trees of the subarray divided by the root number.
Construct the max tree by the given array.
Have you met this question in a real interview?
Example
Given [2, 5, 6, 0, 3, 1], the max tree constructed by this array is:
   6
   / \
  5   3
 /   / \
2   0   1


Challenge
O(n) time and memory.
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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTreeRecur(vector<int>::iterator beg, vector<int>::iterator end) {
        if(beg == end) return NULL;
        if(beg + 1 == end) return (new TreeNode(*beg));
        vector<int>::iterator maxIt = beg;
        int maxVal = *beg;
        for(vector<int>::iterator it = beg; it != end; it++) {
            if(*it > maxVal) {
                maxIt = it;
                maxVal = *it;
            }
        }

        TreeNode* res = new TreeNode(maxVal);
        if(beg == maxIt) {
            res->left = NULL;
        } else {
            res->left = maxTreeRecur(beg, maxIt);
        }
        
        if(maxIt == end - 1) {
            res->right = NULL;
        } else {
            res->right = maxTreeRecur(maxIt + 1, end);
        }
        
        return res;
    }

public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        if(A.empty()) return NULL;
        return maxTreeRecur(A.begin(), A.end());
    }
};
