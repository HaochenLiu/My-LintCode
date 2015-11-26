/*
Spiral Matrix II

Given an integer n, generate a square matrix filled with elements from 1 to n^2 in spiral order.
Have you met this question in a real interview?
Example

Given n = 3,

You should return the following matrix:

[
  [ 1, 2, 3 ],
  [ 8, 9, 4 ],
  [ 7, 6, 5 ]
]
*/

class Solution {
public:
    int step[4][2];
    vector<vector<bool>> canUse;
    
    void dfs(vector<vector<int>> &res, int dep, int maxDep, int dir, int x, int y) {
        if(dep == maxDep) return;
        for(int i = 0; i < 4; ++i) {
            int j = (dir + i) % 4;
            int tx = x + step[j][0];
            int ty = y + step[j][1];
            if(tx >= 0 && tx < res.size() && ty >= 0 && ty < res[0].size() && canUse[tx][ty]) {
                res[tx][ty] = dep + 1;
                canUse[tx][ty] = false;
                dfs(res, dep + 1, maxDep, j, tx, ty);
            }
        }
    }
    
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        // Write your code here
        if(n == 0) {
            vector<vector<int>> res;
            res.clear();
            return res;
        }

        step[0][0] = 0;
        step[0][1] = 1;
        step[1][0] = 1;
        step[1][1] = 0;
        step[2][0] = 0;
        step[2][1] = -1;
        step[3][0] = -1;
        step[3][1] = 0;
        vector<vector<int>> res(n, vector<int>(n, 0));
        canUse.clear();
        canUse.resize(n, vector<bool>(n, true));
        dfs(res, 0, n * n, 0, 0, -1);

        return res;
    }
};
