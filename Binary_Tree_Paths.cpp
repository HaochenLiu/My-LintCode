/*
Binary Tree Paths

Given a binary tree, return all root-to-leaf paths.
Have you met this question in a real interview?
Example

Given the following binary tree:

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

[
  "1->2->5",
  "1->3"
]
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
    void dfs(TreeNode* root, string path, vector<string>& res) {
        if (root == NULL) return;
        path += to_string(root->val);
        if (root->left == NULL && root->right == NULL) {
            res.push_back(path);
            return;
        }
        path += "->";
        if (root->left != NULL) dfs(root->left, path, res);
        if (root->right != NULL) dfs(root->right, path, res);
    }

public:
    /**
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        string path;
        vector<string> res;
        dfs(root, path, res);
        return res;
    }
};
