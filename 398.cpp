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
    Solution() {
        offset.resize(4, vector<int>(2));
        offset[0][0] = -1;
        offset[0][1] = 0;
        offset[1][0] = +1;
        offset[1][1] = 0;
        offset[2][0] = 0;
        offset[2][1] = -1;
        offset[3][0] = 0;
        offset[3][1] = +1;
    }
    /**
     * @param A an integer matrix
     * @return  an integer
     */
    int longestIncreasingContinuousSubsequenceII(vector<vector<int> > &A) {
        d.clear();
        vector<vector<int> > &a = A;
        n = a.size();
        m = n ? a[0].size() : 0;
        int i, j;
        if (n == 0 || m == 0) {
            return 0;
        }
        d.resize(n, vector<int>(m, 0));
        
        int ans = 0;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                ans = max(ans, DFS(i, j, a));
            }
        }
        return ans;
    }
private:
    vector<vector<int> > offset;
    vector<vector<int> > d;
    int n, m;
    
    bool inbound(int x, int y) {
        return x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1;
    }
    
    int DFS(int x, int y, vector<vector<int> > &a) {
        if (d[x][y] != 0) {
            // Use memorization to avoid redundant recursion
            return d[x][y];
        }
        d[x][y] = 1;
        
        int i;
        int x1, y1;
        for (i = 0; i < 4; ++i) {
            x1 = x + offset[i][0];
            y1 = y + offset[i][1];
            if (!inbound(x1, y1) || a[x1][y1] >= a[x][y]) {
                continue;
            }
            d[x][y] = max(d[x][y], DFS(x1, y1, a) + 1);
        }
        return d[x][y];
    }
};
