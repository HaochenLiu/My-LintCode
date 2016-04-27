/*
535. House Robber III

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Have you met this question in a real interview? Yes
Example
  3
 / \
2   3
 \   \ 
  3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

    3
   / \
  4   5
 / \   \ 
1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.
*/

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
    int houseRobber3(TreeNode* root) {
        int ans = 0;
        if(!root)
            return ans;
        dp.clear();
        dfs(root);
        ans = max(dp[root].first, dp[root].second);
        return ans;
    }

    void dfs(TreeNode *root){
        int res = 0;
        dp[root].first = root->val;
        dp[root].second = 0;
        if(root->left){
            dfs(root->left);
            dp[root].first += dp[root->left].second;
            dp[root].second += max(dp[root->left].first, dp[root->left].second);
        }
        if(root->right){
            dfs(root->right);
            dp[root].first += dp[root->right].second;
            dp[root].second += max(dp[root->right].first, dp[root->right].second);
        }
    }

private:
    unordered_map<TreeNode *, pair<int,int> > dp;
};
