/*
398. Longest Increasing Continuous subsequence II

Give you an integer matrix (with row size n, column size m)，find the longest increasing continuous subsequence in this matrix. (The definition of the longest increasing continuous subsequence here can start at any row or column and go up/down/right/left any direction).
Have you met this question in a real interview?
Example
Given a matrix:
[
  [1 ,2 ,3 ,4 ,5],
  [16,17,24,23,6],
  [15,18,25,22,7],
  [14,19,20,21,8],
  [13,12,11,10,9]
]


return 25
Challenge
O(nm) time and memory.
*/

class Solution {
public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int> > &A) {
        // Write your code here
        if(A.empty() || A[0].empty()) return 0;
        int n = A.size();
        int m = A[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int i, j;

        int ans = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                ans = max(ans, dfs(A, dp, i, j, n, m));
            }
        }
        return ans;
    }
private:
    vector<vector<int>> offset;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool inbound(int x, int y, int n, int m) {
        return (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1);
    }
    
    int dfs(vector<vector<int>>& A, vector<vector<int>>& dp, int x, int y, int n, int m) {
        if (dp[x][y] != 0) {
            return dp[x][y];
        }
        dp[x][y] = 1;
        
        int i;
        int nx, ny;
        for (i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (!inbound(nx, ny, n, m) || A[nx][ny] >= A[x][y]) {
                continue;
            }
            dp[x][y] = max(dp[x][y], dfs(A, dp, nx, ny, n, m) + 1);
        }
        return dp[x][y];
    }
};
