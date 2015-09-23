/*
088. Lowest Common Ancestor

Given the root and two nodes in a Binary Tree. Find the lowest common ancestor(LCA) of the two nodes.
The lowest common ancestor is the node with largest depth which is the ancestor of both nodes.
Have you met this question in a real interview?
Example
For the following binary tree:
 4
 / \
3   7
   / \
  5   6


LCA(3, 5) = 4
LCA(5, 6) = 7
LCA(6, 7) = 7
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
    bool getPath(vector<TreeNode*>& path, TreeNode* root, TreeNode* node) {
        vector<TreeNode*> res;
        if(root == NULL) return false;
        if(root == node) {
            path.push_back(node);
            return true;
        }
        
        if(getPath(path, root->left, node) || getPath(path, root->right, node)) {
            path.push_back(root);
            return true;
        }
        return false;
    }

public:
    /**
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        if(root == NULL) return NULL;
        if(A == NULL) return B;
        if(B == NULL) return A;
        vector<TreeNode*> pathA;
        vector<TreeNode*> pathB;
        getPath(pathA, root, A);
        getPath(pathB, root, B);
        int i = pathA.size() - 1;
        int j = pathB.size() - 1;
        while(true) {
            if(pathA[i] != pathB[j]) {
                return pathA[i + 1];
            }
            i--;
            j--;
        }
    }
};
