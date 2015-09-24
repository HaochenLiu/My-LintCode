/*
245. Subtree

You have two every large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.
Have you met this question in a real interview?
Example
T2 is a subtree of T1 in the following case:
      1                3
      / \              / 
T1 = 2   3      T2 =  4
        /
       4


T2 isn't a subtree of T1 in the following case:
      1               3
      / \               \
T1 = 2   3       T2 =    4
        /
       4


Note
A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.
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
    bool isIdentical(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 != NULL && t2 == NULL) return false;
        if(t1 == NULL && t2 != NULL) return false;
        if(t1->val != t2->val) return false;
        return isIdentical(t1->left, t2->left) && isIdentical(t1->right, t2->right);
    }

public:
    /**
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        // write your code here
        if(T2 == NULL) return true;
        if(T1 == NULL) return false;
        if(isIdentical(T1, T2)) return true;
        if(isSubtree(T1->left, T2)) return true;
        if(isSubtree(T1->right, T2)) return true;
        return false;
    }
};
