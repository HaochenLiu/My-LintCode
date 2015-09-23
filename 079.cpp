/*
079. Longest Common Substring

Given two strings, find the longest common substring.
Return the length of it.
Have you met this question in a real interview?
Example
Given A = "ABCD", B = "CBCE", return 2.
Note
The characters in substring should occur continuously in original string. This is different with subsequence.
Challenge
O(n x m) time and memory.

https://en.wikipedia.org/wiki/Longest_common_substring_problem
*/

class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        // write your code here
        int n = A.size();
        int m = B.size();
        if(n == 0 || m == 0) return 0;
        int dp[n][m];
        int res = 0;

        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < n; i++) {
            if(A[i] == B[0]) {
                dp[i][0] = 1;
                res = max(res, dp[i][0]);
            }
        }

        for(int j = 0; j < m; j++) {
            if(A[0] == B[j]) {
                dp[0][j] = 1;
                res = max(res, dp[0][j]);
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(A[i] == B[j]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    res = max(res, dp[i][j]);
                }
            }
        }
        
        return res;
    }
};
