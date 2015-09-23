/*
011. Search Range in Binary Search Tree

Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. Find all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and x is a key of given BST. Return all the keys in ascending order.
Have you met this question in a real interview?
Example
If k1 = 10 and k2 = 22, then your function should return [12, 20, 22].
   20
   /  \
  8   22
 / \
4   12
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
    void searchRangeRecur(TreeNode*& node, vector<int>& res, int k1, int k2) {
        // write your code here
        if(node == NULL) return;
        if(node->val <= k1) {
            if(node->val == k1) {
                res.push_back(node->val);
            }
            if(node->right) {
                searchRangeRecur(node->right, res, k1, k2);
            }
        } else if(node->val >= k2) {
            if(node->val == k2) {
                res.push_back(node->val);
            }
            if(node->left) {
                searchRangeRecur(node->left, res, k1, k2);
            }
        } else {
            res.push_back(node->val);
            if(node->left) {
                searchRangeRecur(node->left, res, k1, k2);
            }
            if(node->right) {
                searchRangeRecur(node->right, res, k1, k2);
            }
        }
    }

public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> res;
        if(root == NULL) return res;
        if(k1 > k2) return res;
        searchRangeRecur(root, res, k1, k2);
        sort(res.begin(), res.end());

        return res;
    }
};
