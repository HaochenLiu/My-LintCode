/*
163. Unique Binary Search Trees

Given n, how many structurally unique BSTs (binary search trees) that store values 1...n?
Have you met this question in a real interview?
Example
Given n = 3, there are a total of 5 unique BST's.
1           3    3       2      1
 \         /    /       / \      \
  3      2     1       1   3      2
 /      /       \                  \
2     1          2                  3
*/

class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        // write your code here
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            for(int j = 0; j < i; j++) {
                dp[i] += (dp[j] * dp[i - j - 1]);
            }
        }
        
        return dp[n];
    }
};
