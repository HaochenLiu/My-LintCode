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

// Cartesian Tree, make it O(n)

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
    TreeNode* maxTree(vector<int> A) {
        if(A.empty()) return NULL;
        int n = A.size();
        stack<TreeNode*> st;
        TreeNode* p;
        TreeNode* p1;
        TreeNode* p2;
        for(int i = 0; i < n; ++i) {
            p = new TreeNode(A[i]);
            if(!st.empty() && A[i] > st.top()->val) {
                p1 = st.top();
                st.pop();
                while(!st.empty() && A[i] > st.top()->val) {
                    p2 = st.top();
                    st.pop();
                    p2->right = p1;
                    p1 = p2;
                }
                p->left = p1;
            }
            st.push(p);
        }
        
        TreeNode* r = st.top();
        st.pop();
        while(!st.empty()) {
            st.top()->right = r;
            r = st.top();
            st.pop();
        }
        return r;
    }
};
