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
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    bool inBound(int x, int y, int n, int m) {
        return ((x >= 0) && (y >= 0) && (x < n) && (y < m));
    }

    int bfs(vector<vector<int>>& A, vector<vector<int>>& dp, int x, int y) {
        int res = 1;
        int n = A.size();
        int m = A[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        while(!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int ox = p.first;
            int oy = p.second;
            for(int i = 0; i < 4; i++) {
                int nx = ox + dx[i];
                int ny = oy + dy[i];
                if(!inBound(nx, ny, n, m)) continue;
                if(A[nx][ny] < A[ox][oy]) continue;
                if(dp[nx][ny] > dp[ox][oy]) continue;
                dp[nx][ny] = dp[ox][oy] + 1;
                res = max(res, dp[nx][ny]);
                q.push(make_pair(nx, ny));
            }
        }
        
        return res;
    }

public:
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int>>& A) {
        // Write your code here
        if(A.empty() || A[0].empty()) return 0;
        int n = A.size();
        int m = A[0].size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vector<vector<int>> dp(n, vector<int>(m, 0));
                dp[i][j] = 1;
                res = max(res, bfs(A, dp, i, j));
            }
        }
        
        return res;
    }
};
