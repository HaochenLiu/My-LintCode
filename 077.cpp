/*
077. Longest Common Subsequence

Given two strings, find the longest common subsequence (LCS).
Your code should return the length of LCS.
Have you met this question in a real interview?
Example
For "ABCD" and "EDCA", the LCS is "A" (or "D", "C"), return 1.
For "ABCD" and "EACB", the LCS is "AC", return 2.
Clarification
What's the definition of Longest Common Subsequence?
https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
http://baike.baidu.com/view/2020307.htm
*/

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        // write your code here
        int n = A.size();
        int m = B.size();
        if(n == 0 || m == 0) return 0;
        int dp[n][m];

        memset(dp, 0, sizeof(dp));
        
        for(int i = 0; i < n; i++) {
            if(A[i] == B[0]) {
                for(int k = i; k < n; k++) {
                    dp[k][0] = 1;
                }
            }
        }

        for(int j = 0; j < m; j++) {
            if(A[0] == B[j]) {
                for(int k = j; k < n; k++) {
                    dp[0][k] = 1;
                }
            }
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(A[i] == B[j]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n - 1][m - 1];
    }
};
